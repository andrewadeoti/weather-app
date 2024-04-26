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
        std::cout << "2. Add Favorite" << std::endl;
        std::cout << "3. Delete Favorites" << std::endl;
        std::cout << "4. View History" << std::endl;
        std::cout << "5. Save" << std::endl;
        std::cout << "6. Delete" << std::endl;
        std::cout << "7. Check Weather Data" << std::endl;
        std::cout << "8. Exit" << std::endl;

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
        break;
    case 2:
        // Add code to handle Add Favorite option
        break;
    case 3:
        // Add code to handle Delete Favorites option
        break;
    case 4:
        // Add code to handle View History option
        break;
    case 5:
        // Add code to handle Save option
        break;
    case 6:
        // Add code to handle Delete option
        break;
    case 7:
        // Add code to handle Check Weather Data option
        break;
    case 8:
        // Add code to handle Exit option
        break;
    default:
        std::cout << "Invalid choice. Please enter a number between 1 and 8." << std::endl;
        break;
    }
}

