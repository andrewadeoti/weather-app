#include "Location.h"
#include <iostream>

std::vector<Location> locations; // Define vector to store locations

void Location::addNewLocation() {
    Location newLocation;

    std::cout << "Enter location ID: ";
    std::cin >> newLocation.id;

    std::cout << "Enter location name: ";
    std::cin.ignore();
    std::getline(std::cin, newLocation.name);

    std::cout << "Enter latitude: ";
    std::cin >> newLocation.latitude;

    std::cout << "Enter longitude: ";
    std::cin >> newLocation.longitude;

    locations.push_back(newLocation);

    std::cout << "New location added successfully." << std::endl;
}

void Location::modifyLocationData() {
    int id;
    std::cout << "Enter location ID to modify: ";
    std::cin >> id;

    for (auto& loc : locations) {
        if (loc.id == id) {
            std::cout << "Enter new location name: ";
            std::cin.ignore();
            std::getline(std::cin, loc.name);

            std::cout << "Enter new latitude: ";
            std::cin >> loc.latitude;

            std::cout << "Enter new longitude: ";
            std::cin >> loc.longitude;

            std::cout << "Location data modified successfully." << std::endl;
            return;
        }
    }

    std::cout << "Location with ID " << id << " not found." << std::endl;
}

void Location::removeLocation() {
    int choice;
    std::cout << "Select removal option:" << std::endl;
    std::cout << "1. Remove by ID" << std::endl;
    std::cout << "2. Remove by Name" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        int id;
        std::cout << "Enter location ID to remove: ";
        std::cin >> id;

        for (auto it = locations.begin(); it != locations.end(); ++it) {
            if (it->id == id) {
                locations.erase(it);
                std::cout << "Location with ID " << id << " removed successfully." << std::endl;
                return;
            }
        }
        std::cout << "Location with ID " << id << " not found." << std::endl;
    }
    else if (choice == 2) {
        std::string name;
        std::cout << "Enter location name to remove: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        for (auto it = locations.begin(); it != locations.end(); ++it) {
            if (it->name == name) {
                locations.erase(it);
                std::cout << "Location \"" << name << "\" removed successfully." << std::endl;
                return;
            }
        }
        std::cout << "Location \"" << name << "\" not found." << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}
