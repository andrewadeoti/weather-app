#include <iostream>
#include "Location.h"
#include "Menu.h"

using namespace std;

int main() {
    LocationManager locationManager; // Instantiate the LocationManager

    // Call addNewLocation function to test
    locationManager.addNewLocation();

    // Call modifyLocationData function to test
    locationManager.modifyLocationData();

    // Call removeLocation function to test
    locationManager.removeLocation();

    // Call mainMenu function to test
    mainMenu();

    return 0;
}
