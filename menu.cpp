#include <iostream>

using namespace std;

void mainMenu() {
    int choice;
    bool confirmed = false;

    do {
        cout << "===== Main Menu =====" << endl;
        cout << "1. Back to Main Menu" << endl;
        cout << "2. Add Favorite" << endl;
        cout << "3. Delete Favorites" << endl;
        cout << "4. View History" << endl;
        cout << "5. Save" << endl;
        cout << "6. Delete" << endl;
        cout << "7. Check Weather Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice (1-8): ";
        cin >> choice;

        // Prompt for confirmation
        cout << "Are you sure you want to select option " << choice << "? (Y/N): ";
        char confirmChoice;
        cin >> confirmChoice;

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
        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        break;
    }
}
