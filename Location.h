#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

using namespace std;

// Define a structure to represent a location
struct Location {
    int id;
    string name;
    double latitude;
    double longitude;
};

// Declare a vector to store locations
extern vector<Location> locations;

class LocationManager {
public:
    // Function to add a new location
    void addNewLocation();

    // Function to modify location data
    void modifyLocationData();

    // Function to remove a location
    void removeLocation();
};

#endif // LOCATION_H
