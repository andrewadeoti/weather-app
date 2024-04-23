#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <ctime>
#include <vector>
#include "menu.h" // Include the menu header file

using namespace rapidjson;
using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

void saveOutputToFile(const string& output) {
    ofstream outputFile("weather_output.txt", ios::app); // Append mode to append to existing file
    if (outputFile.is_open()) {
        outputFile << output << endl;
        cout << "Output saved to 'weather_output.txt'." << endl;
        outputFile.close();
    }
    else {
        cerr << "Unable to save output to file." << endl;
    }
}

void viewHistory() {
    ifstream inputFile("weather_output.txt");
    if (inputFile.is_open()) {
        string line;
        cout << "History of saved and deleted data:" << endl;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    }
    else {
        cerr << "Unable to open history file." << endl;
    }
}

void deleteHistory() {
    if (remove("weather_output.txt") != 0) {
        cerr << "Error deleting history file." << endl;
    }
    else {
        cout << "History file deleted successfully." << endl;
    }
}

void setFavoriteLocation(const string& location) {
    ofstream favLocationFile("favorite_location.txt", ios::app);
    if (favLocationFile.is_open()) {
        favLocationFile << location << endl;
        cout << "Favorite location set to: " << location << endl;
        favLocationFile.close();
    }
    else {
        cerr << "Unable to set favorite location." << endl;
    }
}

void viewFavoriteLocations() {
    ifstream favLocationFile("favorite_location.txt");
    if (favLocationFile.is_open()) {
        string location;
        cout << "Your favorite locations:" << endl;
        while (getline(favLocationFile, location)) {
            cout << location << endl;
        }
        favLocationFile.close();
    }
    else {
        cerr << "Unable to open favorite location file." << endl;
    }
}

void deleteFavoriteLocation(const string& locationToDelete) {
    ifstream inputFile("favorite_location.txt");
    ofstream tempFile("temp.txt");

    if (inputFile.is_open() && tempFile.is_open()) {
        string location;
        while (getline(inputFile, location)) {
            if (location != locationToDelete) {
                tempFile << location << endl;
            }
        }
        inputFile.close();
        tempFile.close();

        if (remove("favorite_location.txt") != 0) {
            cerr << "Error deleting favorite location." << endl;
            return;
        }

        if (rename("temp.txt", "favorite_location.txt") != 0) {
            cerr << "Error renaming temp file." << endl;
            return;
        }

        cout << "Favorite location deleted successfully." << endl;
    }
    else {
        cerr << "Unable to open files for deletion." << endl;
    }
}

void deleteAllFavoriteLocations() {
    if (remove("favorite_location.txt") != 0) {
        cerr << "Error deleting all favorite locations." << endl;
    }
    else {
        cout << "All favorite locations deleted successfully." << endl;
    }
}

int main() {
    CURL* curl = curl_easy_init();

    if (curl) {
        mainMenu(); // Call the mainMenu function to display the menu

        string userInput;

        cout << "Enter location: ";
        cin >> userInput;

        cout << "Do you want to set this as your favorite location? (Y/N): ";
        char favChoice;
        cin >> favChoice;

        if (favChoice == 'Y' || favChoice == 'y') {
            setFavoriteLocation(userInput);
        }

        cout << "Do you want to view your favorite locations? (Y/N): ";
        char viewChoice;
        cin >> viewChoice;

        if (viewChoice == 'Y' || viewChoice == 'y') {
            viewFavoriteLocations();
        }

        string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=";
        geocodingUrl += userInput + "&count=1&language=en&format=json";

        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());

        string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1;
        }

        Document parsedData;
        parsedData.Parse(response_data.c_str());

        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && parsedData["results"].Size() > 0) {
            double latitude = parsedData["results"][0]["latitude"].GetDouble();
            double longitude = parsedData["results"][0]["longitude"].GetDouble();

            string weatherUrl = "https://api.open-meteo.com/v1/forecast?latitude=";
            weatherUrl += to_string(latitude) + "&longitude=" + to_string(longitude) + "&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m";

            curl_easy_setopt(curl, CURLOPT_URL, weatherUrl.c_str());

            string weatherData;
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &weatherData);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                curl_easy_cleanup(curl);
                return 1;
            }

            Document weatherParsedData;
            weatherParsedData.Parse(weatherData.c_str());

            if (weatherParsedData.HasMember("current_weather")) {
                const Value& currentWeather = weatherParsedData["current_weather"];
                double temperature = currentWeather["temperature"].GetDouble();
                double windSpeed = currentWeather["windspeed"].GetDouble();
                int windDirection = currentWeather["winddirection"].GetInt();
                int weatherCode = currentWeather["weathercode"].GetInt();

                cout << "Latitude: " << latitude << endl;
                cout << "Longitude: " << longitude << endl;
                cout << "Temperature: " << temperature << " �C" << endl;
                cout << "Wind Speed: " << windSpeed << " m/s" << endl;
                cout << "Wind Direction: " << windDirection << " degrees" << endl;
                cout << "Weather Code: " << weatherCode << endl;
                cout << "Hourly Data:" << endl;

                if (weatherParsedData.HasMember("hourly")) {
                    const Value& hourly = weatherParsedData["hourly"];
                    const Value& time = hourly["time"];
                    const Value& hourlyTemperature = hourly["temperature_2m"];
                    const Value& hourlyHumidity = hourly["relativehumidity_2m"];
                    const Value& hourlyWindSpeed = hourly["windspeed_10m"];

                    for (SizeType i = 0; i < time.Size(); ++i) {
                        cout << "Time: " << time[i].GetString() << endl;
                        cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " �C" << endl;
                        cout << "Humidity: " << hourlyHumidity[i].GetDouble() << "%" << endl;
                        cout << "Wind Speed: " << hourlyWindSpeed[i].GetDouble() << " m/s" << endl;
                        cout << endl;

                        // Exit the program after printing the first hourly data point
                        if (i == 0) {
                            cout << "Do you want to save the output to a file? (Y/N): ";
                            char choice;
                            cin >> choice;
                            if (choice == 'Y' || choice == 'y') {
                                saveOutputToFile(weatherData);
                            }

                            cout << "Do you want to view history? (Y/N): ";
                            cin >> choice;
                            if (choice == 'Y' || choice == 'y') {
                                viewHistory();
                            }

                            cout << "Do you want to delete history? (Y/N): ";
                            cin >> choice;
                            if (choice == 'Y' || choice == 'y') {
                                deleteHistory();
                            }

                            cout << "Do you want to delete a favorite location? (Y/N): ";
                            cin >> choice;
                            if (choice == 'Y' || choice == 'y') {
                                string locationToDelete;
                                cout << "Enter the location to delete: ";
                                cin >> locationToDelete;
                                deleteFavoriteLocation(locationToDelete);
                            }

                            cout << "Do you want to delete all favorite locations? (Y/N): ";
                            cin >> choice;
                            if (choice == 'Y' || choice == 'y') {
                                deleteAllFavoriteLocations();
                            }

                            curl_easy_cleanup(curl);
                            return 0;
                        }
                    }
                }
            }
            else {
                cerr << "Error: Unable to parse weather data response." << endl;
            }
        }
        else {
            cerr << "Error: Unable to parse geocoding response." << endl;
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}




//
//#include <iostream>
//#include <fstream>
//#include <curl/curl.h>
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <string>
//
//using namespace rapidjson;
//using namespace std;
//
//// Function to save output to a file
//void saveOutputToFile(const string& output) {
//    ofstream outputFile("weather_output.txt");
//    if (outputFile.is_open()) {
//        outputFile << output;
//        cout << "Output saved to 'weather_output.txt'." << endl;
//        outputFile.close();
//    }
//    else {
//        cerr << "Unable to save output to file." << endl;
//    }
//}
//
//// Function to view history
//void viewHistory() {
//    ifstream historyFile("weather_output.txt");
//    if (historyFile.is_open()) {
//        cout << "History of saved data:" << endl;
//        cout << historyFile.rdbuf() << endl;
//        historyFile.close();
//    }
//    else {
//        cerr << "No history available." << endl;
//    }
//}
//
//// Function to delete history
//void deleteHistory() {
//    if (remove("weather_output.txt") != 0) {
//        cerr << "Error deleting history." << endl;
//    }
//    else {
//        cout << "History deleted successfully." << endl;
//    }
//}
//
//// Function to perform HTTP GET request using libcurl
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//    size_t total_size = size * nmemb;
//    output->append(static_cast<char*>(contents), total_size);
//    return total_size;
//}
//
//// Main function
//int main() {
//    CURL* curl = curl_easy_init();
//
//    if (curl) {
//        string userInput;
//        string userTime;
//
//        cout << "Enter location: ";
//        cin >> userInput;
//
//        cout << "Enter time in 24-hour format (HHMM): ";
//        cin >> userTime;
//
//        string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=";
//        geocodingUrl += userInput + "&count=1&language=en&format=json";
//
//        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());
//
//        string response_data;
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
//
//        CURLcode res = curl_easy_perform(curl);
//        if (res != CURLE_OK) {
//            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//            curl_easy_cleanup(curl);
//            return 1;
//        }
//
//        Document parsedData;
//        parsedData.Parse(response_data.c_str());
//
//        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && !parsedData["results"].Empty()) {
//            double latitude = parsedData["results"][0]["latitude"].GetDouble();
//            double longitude = parsedData["results"][0]["longitude"].GetDouble();
//
//            string weatherUrl = "https://api.open-meteo.com/v1/forecast?latitude=";
//            weatherUrl += to_string(latitude) + "&longitude=" + to_string(longitude) + "&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m";
//
//            curl_easy_setopt(curl, CURLOPT_URL, weatherUrl.c_str());
//
//            string weatherData;
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &weatherData);
//
//            res = curl_easy_perform(curl);
//            if (res != CURLE_OK) {
//                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//                curl_easy_cleanup(curl);
//                return 1;
//            }
//
//            Document weatherParsedData;
//            weatherParsedData.Parse(weatherData.c_str());
//
//            if (weatherParsedData.HasMember("current_weather")) {
//                const Value& currentWeather = weatherParsedData["current_weather"];
//                double temperature = currentWeather["temperature"].GetDouble();
//                double windSpeed = currentWeather["windspeed"].GetDouble();
//                int windDirection = currentWeather["winddirection"].GetInt();
//                int weatherCode = currentWeather["weathercode"].GetInt();
//
//                cout << "Latitude: " << latitude << endl;
//                cout << "Longitude: " << longitude << endl;
//                cout << "Temperature: " << temperature << " �C" << endl;
//                cout << "Wind Speed: " << windSpeed << " m/s" << endl;
//                cout << "Wind Direction: " << windDirection << " degrees" << endl;
//                cout << "Weather Code: " << weatherCode << endl;
//                cout << "Hourly Data:" << endl;
//
//                if (weatherParsedData.HasMember("hourly")) {
//                    const Value& hourly = weatherParsedData["hourly"];
//                    const Value& time = hourly["time"];
//                    const Value& hourlyTemperature = hourly["temperature_2m"];
//                    const Value& hourlyHumidity = hourly["relativehumidity_2m"];
//                    const Value& hourlyWindSpeed = hourly["windspeed_10m"];
//
//                    // Find index of user specified time
//                    int userIndex = -1;
//                    for (SizeType i = 0; i < time.Size(); ++i) {
//                        if (strcmp(time[i].GetString(), userTime.c_str()) == 0) {
//                            userIndex = i;
//                            break;
//                        }
//                    }
//
//                    if (userIndex != -1) {
//                        cout << "Time: " << time[userIndex].GetString() << endl;
//                        cout << "Temperature: " << hourlyTemperature[userIndex].GetDouble() << " �C" << endl;
//                        cout << "Humidity: " << hourlyHumidity[userIndex].GetDouble() << "%" << endl;
//                        cout << "Wind Speed: " << hourlyWindSpeed[userIndex].GetDouble() << " m/s" << endl;
//                    }
//                    else {
//                        cerr << "Error: Time not found in data." << endl;
//                    }
//                }
//            }
//            else {
//                cerr << "Error: Unable to parse weather data response." << endl;
//            }
//        }
//        else {
//            cerr << "Error: Unable to parse geocoding response." << endl;
//        }
//
//        curl_easy_cleanup(curl);
//    }
//
//    return 0;
//}


















