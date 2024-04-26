#include "Location.h"
#include "Weather.h" // Include Weather.h if you haven't already
#include <iostream>
#include <curl/curl.h> // Include curl for making HTTP requests

std::vector<Location> locations; // Define vector to store locations

// Function to handle HTTP request using libcurl
size_t curlCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    size_t oldLength = s->size();
    s->resize(oldLength + newLength);
    std::copy((char*)contents, (char*)contents + newLength, s->begin() + oldLength);
    return size * nmemb;
}

void Location::addNewLocation() {
    Location newLocation;

    std::cout << "Enter location name: ";
    std::cin.ignore();
    std::getline(std::cin, newLocation.name);

    // Call the geocoding API to fetch latitude and longitude based on the location name
    std::string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=" + newLocation.name;
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    // Parse the response to extract latitude and longitude
    // Assuming you have a JSON parser or you can manually parse the response string

    // After parsing, assign latitude and longitude values to newLocation.latitude and newLocation.longitude
    // Example:
    // newLocation.latitude = parsedLatitude;
    // newLocation.longitude = parsedLongitude;

    // Call the weather forecast API to fetch weather data for the new location
    std::string weatherForecastUrl = "https://api.open-meteo.com/v1/forecast?latitude=" + std::to_string(newLocation.latitude) + "&longitude=" + std::to_string(newLocation.longitude);
    std::string weatherResponse;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, weatherForecastUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &weatherResponse);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    // Parse the weather forecast response and display the weather data
    // Assuming you have a function in the Weather class to handle this
    // Example:
    // Weather weather;
    // weather.displayWeatherData(weatherResponse);

    locations.push_back(newLocation);

    std::cout << "New location added successfully." << std::endl;
}

