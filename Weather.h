#pragma once
#include "rapidjson/document.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

class Weather {
public:
    void displayHourlyWeather(const Value& hourly);
    void displayDailyWeather(const Value& daily);
    void displayWeatherData(const Document& weatherParsedData);
};
