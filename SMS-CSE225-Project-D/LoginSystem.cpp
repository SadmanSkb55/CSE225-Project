#include "LoginSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

const string GREEN_TEXT = "\033[32m";
const string RESET_TEXT = "\033[0m";

string LoginSystem::getMaskedPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' is the Enter key
        if (ch == '\b' && !password.empty()) { // Handle backspace
            password.pop_back();
            cout << "\b \b";
        } else if (ch != '\b') {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

LoginSystem::LoginSystem() {}

User* LoginSystem::login() {
    string username, password;

    while (true) {
        cout << GREEN_TEXT << "Username: " << RESET_TEXT;
        cin >> username;

        cout << GREEN_TEXT << "Password: " << RESET_TEXT;
        password = getMaskedPassword();

        // Check all user types
        ifstream file;
        string fileUsername, filePassword;

        // Check admin
        file.open("admin.txt");
        while (file >> fileUsername >> filePassword) {
            if (username == fileUsername && password == filePassword) {
                return new Admin(username, password);
            }
        }
        file.close();

        // Check teacher
        file.open("teacher.txt");
        while (file >> fileUsername >> filePassword) {
            if (username == fileUsername && password == filePassword) {
                return new Teacher(username, password);
            }
        }
        file.close();

        // Check student
        file.open("student.txt");
        while (file >> fileUsername >> filePassword) {
            if (username == fileUsername && password == filePassword) {
                return new Student(username, password);
            }
        }
        file.close();

        cout << GREEN_TEXT << "Invalid username or password. Please try again." << RESET_TEXT << endl;
    }
}
