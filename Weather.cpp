// Weather.cpp
#include "Weather.h"
#include <iostream>

void Weather::displayHourlyWeather(const rapidjson::Value& hourly) {
    // Function implementation
}

void Weather::displayDailyWeather(const rapidjson::Value& daily) {
    // Function implementation
}

void Weather::displayWeatherData(const rapidjson::Document& weatherParsedData) {
    // Function implementation
    if (weatherParsedData.HasMember("current_weather")) {
        // Display current weather data

        if (weatherParsedData.HasMember("hourly")) {
            // Display hourly weather data
            const rapidjson::Value& hourly = weatherParsedData["hourly"];
            displayHourlyWeather(hourly);
        }

        if (weatherParsedData.HasMember("daily")) {
            // Display daily weather data
            const rapidjson::Value& daily = weatherParsedData["daily"];
            displayDailyWeather(daily);
        }

        // Add more functionalities here
    }
    else {
        std::cerr << "Error: Unable to parse weather data response." << std::endl;
    }
}
