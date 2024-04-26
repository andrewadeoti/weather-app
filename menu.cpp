#include "Menu.h"
#include "Location.h" // Include Location.h for Location struct
#include <iostream>
#include <vector> // Include vector header for vector usage

void mainMenu() {
    int choice;
    bool confirmed = false;

    do {
        std::cout << "===== Main Menu =====" << std::endl;
        std::cout << "1. Back to Main Menu" << std::endl;
        std::cout << "2. Search Location" << std::endl;
        std::cout << "3. Add Favorite" << std::endl;
        std::cout << "4. Delete Favorites" << std::endl;
        std::cout << "5. View History" << std::endl;
        std::cout << "6. Save" << std::endl;
        std::cout << "7. Delete" << std::endl;
        std::cout << "8. Check Weather Data" << std::endl;
        std::cout << "9. Exit" << std::endl;

        std::cout << "Enter your choice (1-8): ";
        std::cin >> choice;

        // Prompt for confirmation
        std::cout << "Are you sure you want to select option " << choice << "? (Y/N): ";
        char confirmChoice;
        std::cin >> confirmChoice;

        if (confirmChoice == 'Y' || confirmChoice == 'y') {
            confirmed = true;
        }
        else {
            confirmed = false;
        }
    } while (!confirmed);

    // Perform actions based on user's confirmed choice
    switch (choice) {
    case 1:
        // Add code to handle Back to Main Menu option
        std::cout << "Returning to the main menu..." << std::endl;
        break;

    case 2:
        // Add code to handle Add Favorite option
        std::cout << "Searching for location data..." << std::endl;
        std::cout << "Found..." << std::endl;
        // Implement add favorite functionality here
        break;
        // Similar cases for options 3-8

    case 3:
        // Add code to handle Add Favorite option
        std::cout << "Adding favorite location..." << std::endl;
        // Implement add favorite functionality here
        break;
        // Similar cases for options 3-8

    case 4:
        // Add code to handle Delete Favorites option
        std::cout << "Deleting favourites..." << std::endl;
        std::cout << "Deleted..." << std::endl;
        break;
    case 5:
        // Add code to handle View History option
        std::cout << "Viewing history..." << std::endl;
        break;
    case 6:
        // Add code to handle Save option
        std::cout << "Saving data..." << std::endl;
        // Implement saving functionality here
        std::cout << "Data saved successfully." << std::endl;
        break;
    case 7:
        // Add code to handle Delete option
        std::cout << "Deleted successfully..." << std::endl;
        break;
    case 8:
        // Add code to handle Check Weather Data option
        std::cout << "Checking weather data..." << std::endl;
        break;
    case 9:
        // Add code to handle Exit option
        std::cout << "Exiting..." << std::endl;
        break;
    default:
        std::cout << "Invalid choice. Please enter a number between 1 and 8." << std::endl;
        break;
    }
}
