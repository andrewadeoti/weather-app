//#include <iostream>
//
//using namespace std;
//
//void mainMenu() {
//    int choice;
//    bool confirmed = false;
//
//    do {
//        cout << "===== Main Menu =====" << endl;
//        cout << "1. Back to Main Menu" << endl;
//        cout << "2. Add Favorite" << endl;
//        cout << "3. Delete Favorites" << endl;
//        cout << "4. View History" << endl;
//        cout << "5. Save" << endl;
//        cout << "6. Delete" << endl;
//        cout << "7. Check Weather Data" << endl;
//        cout << "8. Exit" << endl;
//
//        cout << "Enter your choice (1-8): ";
//        cin >> choice;
//
//        // Prompt for confirmation
//        cout << "Are you sure you want to select option " << choice << "? (Y/N): ";
//        char confirmChoice;
//        cin >> confirmChoice;
//
//        if (confirmChoice == 'Y' || confirmChoice == 'y') {
//            confirmed = true;
//        }
//        else {
//            confirmed = false;
//        }
//    } while (!confirmed);
//
//    // Perform actions based on user's confirmed choice
//    switch (choice) {
//    case 1:
//        // Add code to handle Back to Main Menu option
//        break;
//    case 2:
//        // Add code to handle Add Favorite option
//        break;
//    case 3:
//        // Add code to handle Delete Favorites option
//        break;
//    case 4:
//        // Add code to handle View History option
//        break;
//    case 5:
//        // Add code to handle Save option
//        break;
//    case 6:
//        // Add code to handle Delete option
//        break;
//    case 7:
//        // Add code to handle Check Weather Data option
//        break;
//    case 8:
//        // Add code to handle Exit option
//        break;
//    default:
//        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
//        break;
//    }
//}



//#include <iostream>
//#include "menu.h"
//
//using namespace std;
//
//void mainMenu() {
//    int choice;
//    bool confirmed = false;
//
//    do {
//        cout << "===== Main Menu =====" << endl;
//        cout << "1. Back to Main Menu" << endl;
//        cout << "2. Add Favorite" << endl;
//        cout << "3. Delete Favorites" << endl;
//        cout << "4. View History" << endl;
//        cout << "5. Save" << endl;
//        cout << "6. Delete" << endl;
//        cout << "7. Check Weather Data" << endl;
//        cout << "8. Exit" << endl;
//
//        cout << "Enter your choice (1-8): ";
//        cin >> choice;
//
//        // Prompt for confirmation
//        cout << "Are you sure you want to select option " << choice << "? (Y/N): ";
//        char confirmChoice;
//        cin >> confirmChoice;
//
//        if (confirmChoice == 'Y' || confirmChoice == 'y') {
//            confirmed = true;
//        }
//        else {
//            confirmed = false;
//        }
//    } while (!confirmed);
//
//    // Perform actions based on user's confirmed choice
//    switch (choice) {
//    case 1:
//        // Add code to handle Back to Main Menu option
//        break;
//    case 2:
//        // Add code to handle Add Favorite option
//        break;
//    case 3:
//        // Add code to handle Delete Favorites option
//        break;
//    case 4:
//        // Add code to handle View History option
//        break;
//    case 5:
//        // Add code to handle Save option
//        break;
//    case 6:
//        // Add code to handle Delete option
//        break;
//    case 7:
//        // Add code to handle Check Weather Data option
//        break;
//    case 8:
//        // Add code to handle Exit option
//        break;
//    default:
//        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
//        break;
//    }
//}


//#include <iostream>
//#include <fstream>
//#include <curl/curl.h>
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <string>
//#include <ctime>
//#include <vector>
//
//#ifdef _WIN32
//#include <io.h>
//#else
//#include <fcntl.h>
//#endif
//
//using namespace rapidjson;
//using namespace std;
//
//struct Location {
//    string id;
//    string name;
//    double latitude;
//    double longitude;
//    bool is_favorite;
//};
//
//struct WeatherData {
//    Location location;
//    time_t timestamp;
//    double temperature;
//    double precipitation;
//    double wind_speed;
//    double wind_direction;
//    double humidity;
//    double cloud_cover;
//    double pressure;
//    double solar_radiation;
//    double air_quality_index;
//};
//
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//    size_t total_size = size * nmemb;
//    output->append(static_cast<char*>(contents), total_size);
//    return total_size;
//}
//
//void saveOutputToFile(const string& output) {
//    ofstream outputFile("weather_output.txt", ios::app);
//    if (outputFile.is_open()) {
//        outputFile << output << endl;
//        cout << "Output saved to 'weather_output.txt'." << endl;
//        outputFile.close();
//    }
//    else {
//        cerr << "Unable to save output to file." << endl;
//    }
//}
//
//void viewHistory() {
//    ifstream inputFile("weather_output.txt");
//    if (inputFile.is_open()) {
//        string line;
//        cout << "History of saved and deleted data:" << endl;
//        while (getline(inputFile, line)) {
//            cout << line << endl;
//        }
//        inputFile.close();
//    }
//    else {
//        cerr << "Unable to open history file." << endl;
//    }
//}
//
//void deleteHistory() {
//    if (remove("weather_output.txt") != 0) {
//        cerr << "Error deleting history file." << endl;
//    }
//    else {
//        cout << "History file deleted successfully." << endl;
//    }
//}
//
//void setFavoriteLocation(const string& location) {
//    ofstream favLocationFile("favorite_location.txt", ios::app);
//    if (favLocationFile.is_open()) {
//        favLocationFile << location << endl;
//        cout << "Favorite location set to: " << location << endl;
//        favLocationFile.close();
//    }
//    else {
//        cerr << "Unable to set favorite location." << endl;
//    }
//}
//
//void viewFavoriteLocations() {
//    ifstream favLocationFile("favorite_location.txt");
//    if (favLocationFile.is_open()) {
//        string location;
//        cout << "Your favorite locations:" << endl;
//        while (getline(favLocationFile, location)) {
//            cout << location << endl;
//        }
//        favLocationFile.close();
//    }
//    else {
//        cerr << "Unable to open favorite location file." << endl;
//    }
//}
//
//void deleteFavoriteLocation(const string& locationToDelete) {
//    ifstream inputFile("favorite_location.txt");
//    ofstream tempFile("temp.txt");
//    if (inputFile.is_open() && tempFile.is_open()) {
//        string location;
//        while (getline(inputFile, location)) {
//            if (location != locationToDelete) {
//                tempFile << location << endl;
//            }
//        }
//        inputFile.close();
//        tempFile.close();
//        if (remove("favorite_location.txt") != 0) {
//            cerr << "Error deleting favorite location." << endl;
//            return;
//        }
//        if (rename("temp.txt", "favorite_location.txt") != 0) {
//            cerr << "Error renaming temp file." << endl;
//            return;
//        }
//        cout << "Favorite location deleted successfully." << endl;
//    }
//    else {
//        cerr << "Unable to open files for deletion." << endl;
//    }
//}
//
//void deleteAllFavoriteLocations() {
//    if (remove("favorite_location.txt") != 0) {
//        cerr << "Error deleting all favorite locations." << endl;
//    }
//    else {
//        cout << "All favorite locations deleted successfully." << endl;
//    }
//}
//
//void outputApiFunctions() {
//    cout << "Functions included in the APIs:" << endl;
//    cout << "https://api.open-meteo.com/v1/forecast?latitude= Functions:" << endl;
//    cout << "current=temperature_2m,relative_humidity_2m,apparent_temperature,is_day,precipitation,rain,showers,snowfall,weather_code,cloud_cover,pressure_msl,surface_pressure,wind_speed_10m,wind_direction_10m,wind_gusts_10m" << endl;
//    cout << "hourly=temperature_2m,relative_humidity_2m,dew_point_2m,apparent_temperature,precipitation_probability,precipitation,rain,showers,snowfall,snow_depth,weather_code,pressure_msl,surface_pressure,cloud_cover,cloud_cover_low,cloud_cover_mid,cloud_cover_high,visibility,evapotranspiration,et0_fao_evapotranspiration,vapour_pressure_deficit,wind_speed_10m,wind_speed_80m,wind_speed_120m,wind_speed_180m,wind_direction_10m,wind_direction_80m,wind_direction_120m,wind_direction_180m,wind_gusts_10m,temperature_80m,temperature_120m,temperature_180m,soil_temperature_0cm,soil_temperature_6cm,soil_temperature_18cm,soil_temperature_54cm,soil_moisture_0_to_1cm,soil_moisture_1_to_3cm,soil_moisture_3_to_9cm,soil_moisture_9_to_27cm,soil_moisture_27_to_81cm" << endl;
//    cout << "daily=weather_code,temperature_2m_max,temperature_2m_min,apparent_temperature_max,apparent_temperature_min,sunrise,sunset,daylight_duration,sunshine_duration,uv_index_max,uv_index_clear_sky_max,precipitation_sum,rain_sum,showers_sum,snowfall_sum,precipitation_hours,precipitation_probability_max,wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant,shortwave_radiation_sum,et0_fao_evapotranspiration" << endl;
//    cout << endl;
//
//    cout << "https://archive-api.open-meteo.com/v1/archive?latitude= Functions:" << endl;
//    cout << "hourly=temperature_2m,relative_humidity_2m,dew_point_2m,apparent_temperature,precipitation,rain,snowfall,snow_depth,weather_code,pressure_msl,surface_pressure,cloud_cover,cloud_cover_low,cloud_cover_mid,cloud_cover_high,et0_fao_evapotranspiration,vapour_pressure_deficit,wind_speed_10m,wind_speed_100m,wind_direction_10m,wind_direction_100m,wind_gusts_10m,soil_temperature_0_to_7cm,soil_temperature_7_to_28cm,soil_temperature_28_to_100cm,soil_temperature_100_to_255cm,soil_moisture_0_to_7cm,soil_moisture_7_to_28cm,soil_moisture_28_to_100cm,soil_moisture_100_to_255cm" << endl;
//    cout << "daily=weather_code,temperature_2m_max,temperature_2m_min,temperature_2m_mean,apparent_temperature_max,apparent_temperature_min,apparent_temperature_mean,sunrise,sunset,daylight_duration,sunshine_duration,precipitation_sum,rain_sum,snowfall_sum,precipitation_hours,wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant,shortwave_radiation_sum,et0_fao_evapotranspiration" << endl;
//    cout << endl;
//
//    cout << "https://api.open-meteo.com/v1/forecast?latitude= Functions:" << endl;
//    cout << "(No specific functions provided)" << endl;
//    cout << endl;
//
//    cout << "https://geocoding-api.open-meteo.com/v1/search?name= Functions:" << endl;
//    cout << "(No specific functions provided)" << endl;
//    cout << endl;
//}
//
//int main() {
//    outputApiFunctions();
//    return 0;
//}


//#pragma once
//#ifndef MENU_H
//#define MENU_H
//
//void mainMenu(); // Function declaration for the main menu
//
//#endif // MENU_H

//menu.cpp
//#include <iostream>
//#include "menu.h"
//
//using namespace std;
//
//void mainMenu() {
//    int choice;
//    bool confirmed = false;
//
//    do {
//        cout << "===== Main Menu =====" << endl;
//        cout << "1. Back to Main Menu" << endl;
//        cout << "2. Add Favorite" << endl;
//        cout << "3. Delete Favorites" << endl;
//        cout << "4. View History" << endl;
//        cout << "5. Save" << endl;
//        cout << "6. Delete" << endl;
//        cout << "7. Check Weather Data" << endl;
//        cout << "8. Exit" << endl;
//
//        cout << "Enter your choice (1-8): ";
//        cin >> choice;
//
//        // Prompt for confirmation
//        cout << "Are you sure you want to select option " << choice << "? (Y/N): ";
//        char confirmChoice;
//        cin >> confirmChoice;
//
//        if (confirmChoice == 'Y' || confirmChoice == 'y') {
//            confirmed = true;
//        }
//        else {
//            confirmed = false;
//        }
//    } while (!confirmed);
//
//    // Perform actions based on user's confirmed choice
//    switch (choice) {
//    case 1:
//        // Add code to handle Back to Main Menu option
//        break;
//    case 2:
//        // Add code to handle Add Favorite option
//        break;
//    case 3:
//        // Add code to handle Delete Favorites option
//        break;
//    case 4:
//        // Add code to handle View History option
//        break;
//    case 5:
//        // Add code to handle Save option
//        break;
//    case 6:
//        // Add code to handle Delete option
//        break;
//    case 7:
//        // Add code to handle Check Weather Data option
//        break;
//    case 8:
//        // Add code to handle Exit option
//        break;
//    default:
//        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
//        break;
//    }
//}



//// the main code that works
//#include <iostream>
//#include <fstream>
//#include <curl/curl.h>
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <string>
//#include <ctime>
//#include <vector>
//#include "menu.h" // Include the menu header file
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
//    ofstream outputFile("weather_output.txt", ios::app); // Append mode to append to existing file
//    if (outputFile.is_open()) {
//        outputFile << output << endl;
//        cout << "Output saved to 'weather_output.txt'." << endl;
//        outputFile.close();
//    }
//    else {
//        cerr << "Unable to save output to file." << endl;
//    }
//}
//
//void viewHistory() {
//    ifstream inputFile("weather_output.txt");
//    if (inputFile.is_open()) {
//        string line;
//        cout << "History of saved and deleted data:" << endl;
//        while (getline(inputFile, line)) {
//            cout << line << endl;
//        }
//        inputFile.close();
//    }
//    else {
//        cerr << "Unable to open history file." << endl;
//    }
//}
//
//void deleteHistory() {
//    if (remove("weather_output.txt") != 0) {
//        cerr << "Error deleting history file." << endl;
//    }
//    else {
//        cout << "History file deleted successfully." << endl;
//    }
//}
//
//void setFavoriteLocation(const string& location) {
//    ofstream favLocationFile("favorite_location.txt", ios::app);
//    if (favLocationFile.is_open()) {
//        favLocationFile << location << endl;
//        cout << "Favorite location set to: " << location << endl;
//        favLocationFile.close();
//    }
//    else {
//        cerr << "Unable to set favorite location." << endl;
//    }
//}
//
//void viewFavoriteLocations() {
//    ifstream favLocationFile("favorite_location.txt");
//    if (favLocationFile.is_open()) {
//        string location;
//        cout << "Your favorite locations:" << endl;
//        while (getline(favLocationFile, location)) {
//            cout << location << endl;
//        }
//        favLocationFile.close();
//    }
//    else {
//        cerr << "Unable to open favorite location file." << endl;
//    }
//}
//
//void deleteFavoriteLocation(const string& locationToDelete) {
//    ifstream inputFile("favorite_location.txt");
//    ofstream tempFile("temp.txt");
//
//    if (inputFile.is_open() && tempFile.is_open()) {
//        string location;
//        while (getline(inputFile, location)) {
//            if (location != locationToDelete) {
//                tempFile << location << endl;
//            }
//        }
//        inputFile.close();
//        tempFile.close();
//
//        if (remove("favorite_location.txt") != 0) {
//            cerr << "Error deleting favorite location." << endl;
//            return;
//        }
//
//        if (rename("temp.txt", "favorite_location.txt") != 0) {
//            cerr << "Error renaming temp file." << endl;
//            return;
//        }
//
//        cout << "Favorite location deleted successfully." << endl;
//    }
//    else {
//        cerr << "Unable to open files for deletion." << endl;
//    }
//}
//
//void deleteAllFavoriteLocations() {
//    if (remove("favorite_location.txt") != 0) {
//        cerr << "Error deleting all favorite locations." << endl;
//    }
//    else {
//        cout << "All favorite locations deleted successfully." << endl;
//    }
//}
//
//int main() {
//    CURL* curl = curl_easy_init();
//
//    if (curl) {
//        mainMenu(); // Call the mainMenu function to display the menu
//
//        string userInput;
//
//        cout << "Enter location: ";
//        cin >> userInput;
//
//        cout << "Do you want to set this as your favorite location? (Y/N): ";
//        char favChoice;
//        cin >> favChoice;
//
//        if (favChoice == 'Y' || favChoice == 'y') {
//            setFavoriteLocation(userInput);
//        }
//
//        cout << "Do you want to view your favorite locations? (Y/N): ";
//        char viewChoice;
//        cin >> viewChoice;
//
//        if (viewChoice == 'Y' || viewChoice == 'y') {
//            viewFavoriteLocations();
//        }
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
//        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && parsedData["results"].Size() > 0) {
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
//
//                            cout << "Do you want to view history? (Y/N): ";
//                            cin >> choice;
//                            if (choice == 'Y' || choice == 'y') {
//                                viewHistory();
//                            }
//
//                            cout << "Do you want to delete history? (Y/N): ";
//                            cin >> choice;
//                            if (choice == 'Y' || choice == 'y') {
//                                deleteHistory();
//                            }
//
//                            cout << "Do you want to delete a favorite location? (Y/N): ";
//                            cin >> choice;
//                            if (choice == 'Y' || choice == 'y') {
//                                string locationToDelete;
//                                cout << "Enter the location to delete: ";
//                                cin >> locationToDelete;
//                                deleteFavoriteLocation(locationToDelete);
//                            }
//
//                            cout << "Do you want to delete all favorite locations? (Y/N): ";
//                            cin >> choice;
//                            if (choice == 'Y' || choice == 'y') {
//                                deleteAllFavoriteLocations();
//                            }
//
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




//idk
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
//                        cout << "Temperature: " << hourlyTemperature[userIndex].GetDouble() << " °C" << endl;
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





// 2
// only shows latitude and longtitude after user inputs location

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



//3
// decision code search/full
//#include <iostream>
//#include <fstream>
//#include <curl/curl.h>
//#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <string>
//#include <ctime>
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
//    ofstream outputFile("weather_data.txt");
//    if (outputFile.is_open()) {
//        outputFile << output << endl;
//        cout << "Output saved to 'weather_data.txt'." << endl;
//        outputFile.close();
//    }
//    else {
//        cerr << "Unable to save output to file." << endl;
//    }
//}
//
//void saveHistory(const string& history) {
//    ofstream historyFile("history.txt", ios::app);
//    if (historyFile.is_open()) {
//        historyFile << history << endl;
//        cout << "History saved to 'history.txt'." << endl;
//        historyFile.close();
//    }
//    else {
//        cerr << "Unable to save history to file." << endl;
//    }
//}
//
//void viewHistory() {
//    ifstream historyFile("history.txt");
//    if (historyFile.is_open()) {
//        string line;
//        cout << "History:" << endl;
//        while (getline(historyFile, line)) {
//            cout << line << endl;
//        }
//        historyFile.close();
//    }
//    else {
//        cerr << "Unable to open history file." << endl;
//    }
//}
//
//void deleteHistory() {
//    if (remove("history.txt") != 0) {
//        cerr << "Error deleting history file." << endl;
//    }
//    else {
//        cout << "History file deleted successfully." << endl;
//    }
//}
//
//void searchByTime(const Value& time, const Value& hourlyTemperature, const Value& hourlyHumidity, const Value& hourlyWindSpeed) {
//    cout << "Enter time to search (HHMM in 24-hour format): ";
//    string searchTime;
//    cin >> searchTime;
//
//    for (SizeType i = 0; i < time.Size(); ++i) {
//        if (searchTime == time[i].GetString()) {
//            cout << "Time: " << time[i].GetString() << endl;
//            cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " °C" << endl;
//            cout << "Humidity: " << hourlyHumidity[i].GetDouble() << "%" << endl;
//            cout << "Wind Speed: " << hourlyWindSpeed[i].GetDouble() << " m/s" << endl;
//            return;
//        }
//    }
//    cout << "No data available for the specified time." << endl;
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
//        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && parsedData["results"].Size() > 0) {
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
//            saveOutputToFile(weatherData);
//            saveHistory(weatherData);
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
//                    cout << "Do you want to search by time or view full data? (S/F): ";
//                    char choice;
//                    cin >> choice;
//
//                    if (choice == 'S' || choice == 's') {
//                        searchByTime(time, hourlyTemperature, hourlyHumidity, hourlyWindSpeed);
//                    }
//                    else {
//                        for (SizeType i = 0; i < time.Size(); ++i) {
//                            cout << "Time: " << time[i].GetString() << endl;
//                            cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " °C" << endl;
//                            cout << "Humidity: " << hourlyHumidity[i].GetDouble() << "%" << endl;
//                            cout << "Wind Speed: " << hourlyWindSpeed[i].GetDouble() << " m/s" << endl;
//                            cout << endl;
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





// 4
// HHMM format 
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
//                        cout << "Temperature: " << hourlyTemperature[userIndex].GetDouble() << " °C" << endl;
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

//First code  



//#include <iostream>    



//#include <curl/curl.h>    



//#include "rapidjson/document.h"    



//  



//using namespace rapidjson;  



//  



//// Callback function to write the received data    



//  



//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {  



//  



//    size_t total_size = size * nmemb;  



//  



//    output->append(static_cast<char*>(contents), total_size);  



//  



//    return total_size;  



//  



//}  



//  



//void main() {  



//  



//    // Initialize libcurl    



//  



//    CURL* curl = curl_easy_init();  



//  



//  



//    if (curl) {  



//  



//        // Set the URL to Google's homepage    



//  



//  



//        const char* url = "https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m";  



//  



//        curl_easy_setopt(curl, CURLOPT_URL, url);  



//  



//  



//        // Set the callback function to handle received data    



//  



//        std::string response_data;  



//  



//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  



//  



//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);  



//  



//        // Perform the HTTP GET request    



//  



//        CURLcode res = curl_easy_perform(curl);  



//  



//        // Check for errors    



//  



//        if (res != CURLE_OK) {  



//  



//            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));  



//  



//        }  



//  



//        else {  



//  



//            long http_response_code;  



//  



//            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_response_code);  



//  



//            std::cout << "HTTP Response Code: " << http_response_code << std::endl;  



//  



//        }  



//  



//        // Parse the JSON string    



//  



//        Document parsedData;  



//  



//        parsedData.Parse(response_data.c_str());  



//  



//  



//        if (parsedData.HasParseError()) {  



//  



//            std::cerr << "Error parsing JSON." << std::endl;  



//  



//        }  



//        // Access specific information    



//  



//        double latitude = parsedData["latitude"].GetDouble();  



//  



//        double longitude = parsedData["longitude"].GetDouble();  



//  



//        double currentTemperature = parsedData["current"]["temperature_2m"].GetDouble();  



//  



//        double currentWindSpeed = parsedData["current"]["wind_speed_10m"].GetDouble();  



//  



//        // Access hourly data    



//  



//  



//  



//        const Value& hourlyTime = parsedData["hourly"]["time"];  



//  



//        const Value& hourlyTemperature = parsedData["hourly"]["temperature_2m"];  



//  



//        const Value& hourlyHumidity = parsedData["hourly"]["relative_humidity_2m"];  



//  



//        const Value& hourlyWindSpeed = parsedData["hourly"]["wind_speed_10m"];  



//  



//        // Output values (replace with your desired processing)    



//  



//  



//  



//        std::cout << "Latitude: " << latitude << std::endl;  



//  



//        std::cout << "Longitude: " << longitude << std::endl;  



//  



//        std::cout << "Current Temperature: " << currentTemperature << std::endl;  



//  



//        std::cout << "Current Wind Speed: " << currentWindSpeed << std::endl;  



//  



//        std::cout << "hourly" << std::endl;  



//  



//        std::cout << "Time: " << hourlyTime[0].GetString() << std::endl;  



//  



//  



//        std::cout << "Temperature: " << hourlyTemperature[0].GetDouble() << std::endl;  



//  



//  



//        std::cout << "Humidity: " << hourlyHumidity[0].GetDouble() << std::endl;  



//  



//  



//        std::cout << "WindSpeed: " << hourlyWindSpeed[0].GetDouble() << std::endl;  



//  



//  



//        // Cleanup    



//  



//        curl_easy_cleanup(curl);  



//  



//    }  



//} 