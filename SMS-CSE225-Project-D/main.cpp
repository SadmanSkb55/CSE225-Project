#include "User.h"
#include "LoginSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

void displayStudentMenu() {
    cout << "Student Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Advise course" << endl;
    cout << "4. Count CGPA" << endl;
    cout << "5. Logout" << endl;
}

void displayAdminMenu() {
    cout << "Admin Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Add course" << endl;
    cout << "4. Remove course" << endl;
    cout << "5. Logout" << endl;
}

void displayTeacherMenu() {
    cout << "Teacher Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Advise course" << endl;
    cout << "4. Student grading" << endl;
    cout << "5. Logout" << endl;
}

int main() {
    LoginSystem loginSystem;
    int choice;

    while (true) {
        cout << "----- Main Menu -----" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                User* loggedInUser = loginSystem.login();
                if (loggedInUser) {
                    if (dynamic_cast<Student*>(loggedInUser)) {
                        // Student specific menu
                        while (true) {
                            displayStudentMenu();
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice) {
                                // Implement student menu functionality
                                case 1:
                                    cout << "Showing all courses..." << endl;
                                    break;
                                case 2:
                                    cout << "Showing specific courses..." << endl;
                                    break;
                                case 3:
                                    cout << "Advising a course..." << endl;
                                    break;
                                case 4:
                                    cout << "Counting CGPA..." << endl;
                                    break;
                                case 5:
                                    cout << "Logging out." << endl;
                                    delete loggedInUser;
                                    loggedInUser = nullptr;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                    break;
                            }

                            if (loggedInUser == nullptr)
                                break;
                        }
                    } else if (dynamic_cast<Teacher*>(loggedInUser)) {
                        // Teacher specific menu
                        while (true) {
                            displayTeacherMenu();
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice) {
                                // Implement teacher menu functionality
                                case 1:
                                    cout << "Showing all courses..." << endl;
                                    break;
                                case 2:
                                    cout << "Showing specific courses..." << endl;
                                    break;
                                case 3:
                                    cout << "Advising a course..." << endl;
                                    break;
                                case 4:
                                    cout << "Grading a student..." << endl;
                                    break;
                                case 5:
                                    cout << "Logging out." << endl;
                                    delete loggedInUser;
                                    loggedInUser = nullptr;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                    break;
                            }

                            if (loggedInUser == nullptr)
                                break;
                        }
                    } else if (dynamic_cast<Admin*>(loggedInUser)) {
                        // Admin specific menu
                        while (true) {
                            displayAdminMenu();
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice) {
                                // Implement admin menu functionality
                                case 1:
                                    cout << "Showing all courses..." << endl;
                                    break;
                                case 2:
                                    cout << "Showing specific courses..." << endl;
                                    break;
                                case 3:
                                    cout << "Adding a course..." << endl;
                                    break;
                                case 4:
                                    cout << "Removing a course..." << endl;
                                    break;
                                case 5:
                                    cout << "Logging out." << endl;
                                    delete loggedInUser;
                                    loggedInUser = nullptr;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                                    break;
                            }

                            if (loggedInUser == nullptr)
                                break;
                        }
                    }

                    // After handling specific user actions, break to main menu
                    break;
                }
                break;
            }
            case 2:
                // Handle signup functionality
                cout << "Signup functionality not implemented yet." << endl;
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
