// location.h
#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

struct Location {
    int id = 0; // Initialize id to 0
    std::string name;
    double latitude = 0.0; // Initialize latitude to 0.0
    double longitude = 0.0; // Initialize longitude to 0.0

    // Member functions
    void addNewLocation();
    void modifyLocationData();
    void removeLocation();
};

#endif // LOCATION_H
