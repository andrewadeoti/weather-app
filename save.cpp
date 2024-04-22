


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