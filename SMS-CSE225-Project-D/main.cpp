#include "User.h"
#include "LoginSystem.h"
#include <iostream>

using namespace std;

const string GREEN_TEXT = "\033[32m";
const string RESET_TEXT = "\033[0m";

void displayMenu() {
    cout << GREEN_TEXT << "1. Login" << endl;
    cout << "2. Signup" << endl;  // To be implemented later
    cout << "3. Exit" << RESET_TEXT << endl;
}

int main() {
    LoginSystem loginSystem;
    int choice;

    while (true) {
        displayMenu();
        cout << GREEN_TEXT << "Enter your choice: " << RESET_TEXT;
        cin >> choice;

        switch (choice) {
            case 1: {
                User* loggedInUser = loginSystem.login();
                if (loggedInUser) {
                    loggedInUser->display();
                    delete loggedInUser;
                }
                break;
            }
            case 2:
                cout << GREEN_TEXT << "Signup functionality is not implemented yet." << RESET_TEXT << endl;
                break;
            case 3:
                cout << GREEN_TEXT << "Exiting the program." << RESET_TEXT << endl;
                return 0;
            default:
                cout << GREEN_TEXT << "Invalid choice. Please try again." << RESET_TEXT << endl;
        }
    }

    return 0;
}
