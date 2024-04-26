#include "Weather.h"

void Weather::displayHourlyWeather(const Value& hourly) {
    const Value& time = hourly["time"];
    const Value& hourlyTemperature = hourly["temperature_2m"];
    const Value& hourlyHumidity = hourly["relativehumidity_2m"];
    const Value& hourlyWindSpeed = hourly["windspeed_10m"];
    const Value& hourlyPrecipitation = hourly["precipitation"];
    const Value& hourlyPressure = hourly["pressure"];
    const Value& hourlyCloudiness = hourly["cloudiness"];
    const Value& hourlySolarRadiation = hourly["solarradiation"];
    const Value& hourlyPressureLevels = hourly["pressurelevels"];

    for (SizeType i = 0; i < time.Size(); ++i) {
        cout << "Time: " << time[i].GetString() << endl;
        cout << "Temperature: " << hourlyTemperature[i].GetDouble() << " °C" << endl;
        cout << "Humidity: " << hourlyHumidity[i].GetDouble() << "%" << endl;
        cout << "Wind Speed: " << hourlyWindSpeed[i].GetDouble() << " m/s" << endl;
        cout << "Precipitation: " << hourlyPrecipitation[i].GetDouble() << " mm" << endl;
        cout << "Pressure: " << hourlyPressure[i].GetDouble() << " hPa" << endl;
        cout << "Cloudiness: " << hourlyCloudiness[i].GetDouble() << "%" << endl;
        cout << "Solar Radiation: " << hourlySolarRadiation[i].GetDouble() << " W/m^2" << endl;

        // Display pressure levels
        const Value& pressureLevels = hourlyPressureLevels[i];
        for (SizeType j = 0; j < pressureLevels.Size(); ++j) {
            cout << "Pressure Level " << j + 1 << ": " << pressureLevels[j].GetDouble() << " hPa" << endl;
        }

        cout << endl;

        // Exit after printing the first hourly data point
        if (i == 0) {
            // Add save to file option, view history, delete history, delete favorite location, delete all favorite locations here
        }
    }
}

void Weather::displayDailyWeather(const Value& daily) {
    const Value& sunrise = daily["sunrise"];
    const Value& sunset = daily["sunset"];
    const Value& rainSum = daily["rain_sum"];

    cout << "Sunrise: " << sunrise.GetString() << endl;
    cout << "Sunset: " << sunset.GetString() << endl;
    cout << "Rain Sum: " << rainSum.GetDouble() << " mm" << endl;
}

void Weather::displayWeatherData(const Document& weatherParsedData) {
    if (weatherParsedData.HasMember("current_weather")) {
        // Display current weather data

        if (weatherParsedData.HasMember("hourly")) {
            // Display hourly weather data
            const Value& hourly = weatherParsedData["hourly"];
            displayHourlyWeather(hourly);
        }

        if (weatherParsedData.HasMember("daily")) {
            // Display daily weather data
            const Value& daily = weatherParsedData["daily"];
            displayDailyWeather(daily);
        }

        // Add more functionalities here
    }
    else {
        cerr << "Error: Unable to parse weather data response." << endl;
    }
}
