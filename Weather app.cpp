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



//Second code 



#include <iostream> 

#include <curl/curl.h> 

#include "rapidjson/document.h" 



using namespace rapidjson;



// Callback function to write the received data 

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {

    size_t total_size = size * nmemb;

    output->append(static_cast<char*>(contents), total_size);

    return total_size;

}



int main() {

    // Initialize libcurl 

    CURL* curl = curl_easy_init();



    if (curl) {

        std::string userInput;

        std::cout << "Enter location: ";

        std::cin >> userInput;



        // Construct URL for geocoding API 

        std::string geocodingUrl = "https://geocoding-api.open-meteo.com/v1/search?name=";

        geocodingUrl += userInput + "&count=1&language=en&format=json";



        curl_easy_setopt(curl, CURLOPT_URL, geocodingUrl.c_str());



        // Set the callback function to handle received data 

        std::string response_data;

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);



        // Perform the HTTP GET request 

        CURLcode res = curl_easy_perform(curl);



        // Check for errors 

        if (res != CURLE_OK) {

            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

            curl_easy_cleanup(curl);

            return 1; // return error code 

        }



        // Parse the JSON string 

        Document parsedData;

        parsedData.Parse(response_data.c_str());



        if (parsedData.HasMember("results") && parsedData["results"].IsArray() && !parsedData["results"].Empty()) {

            double latitude = parsedData["results"][0]["latitude"].GetDouble();

            double longitude = parsedData["results"][0]["longitude"].GetDouble();



            // Output latitude and longitude 

            std::cout << "Latitude: " << latitude << std::endl;

            std::cout << "Longitude: " << longitude << std::endl;

        }

        else {

            std::cerr << "Error: Unable to parse geocoding response." << std::endl;

            curl_easy_cleanup(curl);

            return 1; // return error code 

        }



        // Cleanup 

        curl_easy_cleanup(curl);

    }



    return 0;

}





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












