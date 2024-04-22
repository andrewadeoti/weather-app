#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <ctime>

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

int main() {
    CURL* curl = curl_easy_init();

    if (curl) {
        string userInput;

        cout << "Enter location: ";
        cin >> userInput;

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
                cout << "Temperature: " << temperature << " °C" << endl;
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
                        cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " °C" << endl;
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
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//    size_t total_size = size * nmemb;
//    output->append(static_cast<char*>(contents), total_size);
//    return total_size;
//}
//
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
//int main() {
//    CURL* curl = curl_easy_init();
//
//    if (curl) {
//        string userInput;
//
//        cout << "Enter location: ";
//        cin >> userInput;
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
//                cout << "Temperature: " << temperature << " °C" << endl;
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
//                    for (SizeType i = 0; i < time.Size(); ++i) {
//                        cout << "Time: " << time[i].GetString() << endl;
//                        cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " °C" << endl;
//                        cout << "Humidity: " << hourlyHumidity[i].GetDouble() << "%" << endl;
//                        cout << "Wind Speed: " << hourlyWindSpeed[i].GetDouble() << " m/s" << endl;
//                        cout << endl;
//
//                        // Exit the program after printing the first hourly data point
//                        if (i == 0) {
//                            cout << "Do you want to save the output to a file? (Y/N): ";
//                            char choice;
//                            cin >> choice;
//                            if (choice == 'Y' || choice == 'y') {
//                                saveOutputToFile(weatherData);
//                            }
//                            curl_easy_cleanup(curl);
//                            return 0;
//                        }
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
// when the output is displayed on the console, the user is given an option to save if the user s to press Y (yes)then it saves the console output into weather_output.txt
// if the user is to press N (no)then it deletes the output displayed.







//#include <iostream>
//#include <curl/curl.h>
//#include "rapidjson/document.h"
//
//using namespace rapidjson;
//
//// Callback function to write the received data
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//    size_t total_size = size * nmemb;
//    output->append(static_cast<char*>(contents), total_size);
//    return total_size;
//}
//
//int main() {
//    // Initialize libcurl
//    CURL* curl = curl_easy_init();
//
//    if (curl) {
//        std::string userInput;
//        std::cout << "Enter location: ";
//        std::cin >> userInput;
//
//        // Construct URL for geocoding API
//        std::string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=";
//        geocodingUrl += userInput + "&count=1&language=en&format=json";
//
//        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());
//
//        // Set the callback function to handle received data
//        std::string response_data;
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
//
//        // Perform the HTTP GET request
//        CURLcode res = curl_easy_perform(curl);
//
//        // Check for errors
//        if (res != CURLE_OK) {
//            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//            curl_easy_cleanup(curl);
//            return 1; // return error code
//        }
//
//        // Parse the JSON string
//        Document parsedData;
//        parsedData.Parse(response_data.c_str());
//
//        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && !parsedData["results"].Empty()) {
//            double latitude = parsedData["results"][0]["latitude"].GetDouble();
//            double longitude = parsedData["results"][0]["longitude"].GetDouble();
//
//            // Output latitude and longitude
//            std::cout << "Latitude: " << latitude << std::endl;
//            std::cout << "Longitude: " << longitude << std::endl;
//        }
//        else {
//            std::cerr << "Error: Unable to parse geocoding response." << std::endl;
//            curl_easy_cleanup(curl);
//            return 1; // return error code
//        }
//
//        // Cleanup
//        curl_easy_cleanup(curl);
//    }
//
//    return 0;
//}












