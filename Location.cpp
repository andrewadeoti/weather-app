#include <iostream>
#include "Location.h"

using namespace std;

// Define the locations vector
vector<Location> locations;

// Function to add a new location
void LocationManager::addNewLocation() {
    Location newLocation;

    // Prompt user to enter location details
    cout << "Enter location ID: ";
    cin >> newLocation.id;

    cout << "Enter location name: ";
    cin.ignore();
    getline(cin, newLocation.name);

    cout << "Enter latitude: ";
    cin >> newLocation.latitude;

    cout << "Enter longitude: ";
    cin >> newLocation.longitude;

    // Add the new location to the vector
    locations.push_back(newLocation);

    cout << "New location added successfully." << endl;
}

// Function to modify location data
void LocationManager::modifyLocationData() {
    int id;
    cout << "Enter location ID to modify: ";
    cin >> id;

    // Find location with the given ID
    for (auto& loc : locations) {
        if (loc.id == id) {
            // Prompt user to enter new details
            cout << "Enter new location name: ";
            cin.ignore();
            getline(cin, loc.name);

            cout << "Enter new latitude: ";
            cin >> loc.latitude;

            cout << "Enter new longitude: ";
            cin >> loc.longitude;

            cout << "Location data modified successfully." << endl;
            return;
        }
    }

    cout << "Location with ID " << id << " not found." << endl;
}

// Function to remove a location
void LocationManager::removeLocation() {
    int choice;
    cout << "Select removal option:" << endl;
    cout << "1. Remove by ID" << endl;
    cout << "2. Remove by Name" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter location ID to remove: ";
        cin >> id;

        // Find and remove location with the given ID
        for (auto it = locations.begin(); it != locations.end(); ++it) {
            if (it->id == id) {
                locations.erase(it);
                cout << "Location with ID " << id << " removed successfully." << endl;
                return;
            }
        }
        cout << "Location with ID " << id << " not found." << endl;
    }
    else if (choice == 2) {
        string name;
        cout << "Enter location name to remove: ";
        cin.ignore();
        getline(cin, name);

        // Find and remove location with the given name
        for (auto it = locations.begin(); it != locations.end(); ++it) {
            if (it->name == name) {
                locations.erase(it);
                cout << "Location \"" << name << "\" removed successfully." << endl;
                return;
            }
        }
        cout << "Location \"" << name << "\" not found." << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}
