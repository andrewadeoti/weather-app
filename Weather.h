//weather.h
#pragma once
#ifndef WEATHER_H
#define WEATHER_H

#include "rapidjson/document.h"
#include <iostream>

class Weather {
public:
    void displayHourlyWeather(const rapidjson::Value& hourly);
    void displayDailyWeather(const rapidjson::Value& daily);
    void displayWeatherData(const rapidjson::Document& weatherParsedData);
};

#endif // WEATHER_H
