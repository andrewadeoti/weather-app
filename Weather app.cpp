#include <iostream>  // Standard input/output stream
#include <fstream>   // File stream
#include <curl/curl.h>  // cURL library for making HTTP requests
#include "rapidjson/document.h"  // JSON parsing library
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>    // String manipulation
#include <ctime>     // Time manipulation
#include <vector>    // Dynamic array container

#ifdef _WIN32
#include <io.h>  // For _open_osfhandle on Windows
#else
#include <fcntl.h>  // For open on non-Windows systems
#endif

using namespace rapidjson;  // Namespace for rapidjson library
using namespace std;        // Namespace for standard library

// Data Structures
struct Location {
    string id;
    string name;
    double latitude;
    double longitude;
    bool is_favorite;
};

struct WeatherData {
    Location location;
    time_t timestamp;
    double temperature;
    double precipitation;
    double wind_speed;
    double wind_direction;
    double humidity;
    double cloud_cover;
    double pressure;
    double solar_radiation;
    double air_quality_index;
};

// Utility Functions

// Write callback function for libcurl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

// Function to save output to file
void saveOutputToFile(const string& output) {
    ofstream outputFile("weather_output.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << output << endl;
        cout << "Output saved to 'weather_output.txt'." << endl;
        outputFile.close();
    }
    else {
        cerr << "Unable to save output to file." << endl;
    }
}

// Function to view history from file
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

// Function to delete history file
void deleteHistory() {
    if (remove("weather_output.txt") != 0) {
        cerr << "Error deleting history file." << endl;
    }
    else {
        cout << "History file deleted successfully." << endl;
    }
}

// Function to set favorite location
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

// Function to view favorite locations
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

// Function to delete a specific favorite location
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

// Function to delete all favorite locations
void deleteAllFavoriteLocations() {
    if (remove("favorite_location.txt") != 0) {
        cerr << "Error deleting all favorite locations." << endl;
    }
    else {
        cout << "All favorite locations deleted successfully." << endl;
    }
}

// Main Function
int main() {
    CURL* curl = curl_easy_init();  // Initialize cURL
    if (curl) {
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

        // Constructing the URL for geocoding API
        string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=";
        geocodingUrl += userInput + "&count=1&language=en&format=json";
        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());  // Set URL for cURL request
        string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Set write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);      // Set data to write to
        CURLcode res = curl_easy_perform(curl);  // Perform cURL request
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1;
        }

        // Parse JSON response from geocoding API
        Document parsedData;
        parsedData.Parse(response_data.c_str());
        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && parsedData["results"].Size() > 0) {
            double latitude = parsedData["results"][0]["latitude"].GetDouble();
            double longitude = parsedData["results"][0]["longitude"].GetDouble();

            // Constructing the URL for weather API
            string weatherUrl = "https://api.open-meteo.com/v1/forecast?latitude=";
            weatherUrl += to_string(latitude) + "&longitude=" + to_string(longitude) + "&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m";
            curl_easy_setopt(curl, CURLOPT_URL, weatherUrl.c_str());  // Set URL for cURL request
            string weatherData;
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Set write callback function
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &weatherData);      // Set data to write to
            res = curl_easy_perform(curl);  // Perform cURL request
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                curl_easy_cleanup(curl);
                return 1;
            }

            // Parse JSON response from weather API
            Document weatherParsedData;
            weatherParsedData.Parse(weatherData.c_str());
            if (weatherParsedData.HasMember("current_weather")) {
                const Value& currentWeather = weatherParsedData["current_weather"];
                double temperature = currentWeather["temperature"].GetDouble();
                double windSpeed = currentWeather["windspeed"].GetDouble();
                int windDirection = currentWeather["winddirection"].GetInt();
                int weatherCode = currentWeather["weathercode"].GetInt();

                // Display current weather data
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

                    // Display hourly weather data
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

                            curl_easy_cleanup(curl);  // Clean up cURL handle
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

        curl_easy_cleanup(curl);  // Clean up cURL handle
    }

    return 0;
}






//Here's how the code works:
//
//Header Includes : Includes necessary header files such as <iostream>, <fstream>, <curl / curl.h>, and others for input / output operations, file handling, cURL library, and JSON parsing.

//Namespace Usage : The code uses namespaces rapidjson and std for the rapidjson library and standard library functionalities.

//Data Structures : Defines two structs Location and WeatherData to represent location information and weather data respectively.

//Utility Functions : Defines utility functions like WriteCallback(a callback function for libcurl to handle writing data), functions for saving output to a file, viewing history, managing favorite locations, and deleting them.

//Main Function :
//Initializes a cURL handle.
//Prompts the user to enter a location.
//Asks the user if they want to set the entered location as their favorite.
//Asks if the user wants to view their favorite locations.
//Constructs the URL for geocoding API to get latitude and longitude of the entered location.
//Performs an HTTP request to the geocoding API using cURL and fetches the response.
//Parses the JSON response to extract latitude and longitude.
//Constructs the URL for weather API using latitude and longitude obtained from the geocoding response.
//Performs another HTTP request to the weather API using cURL and fetches the weather data.
//Parses the weather data JSON response.
//Displays current weather data including temperature, wind speed, wind direction, and weather code.
//If available, displays hourly weather data such as temperature, humidity, and wind speed.
//Provides options to save the output to a file, view history, delete history, delete a favorite location, and delete all favorite locations.
//Cleans up the cURL handle and exits the program.

//cURL Usage : Utilizes the cURL library to make HTTP requests to geocoding and weather APIs.It sets the appropriate URLs, defines a callback function to handle writing data, and performs the requests.

//JSON Parsing : Utilizes the rapidjson library to parse JSON responses received from the APIs.It extracts relevant data such as latitude, longitude, temperature, wind speed, etc.

//User Interaction : Throughout the program, it interacts with the user through the console, prompting for input and displaying information and options.It allows users to set favorites, view favorites, and perform various actions related to data management.

//Overall, this program serves as a simple weather application that fetches and displays weather data based on user input while providing options for data management.