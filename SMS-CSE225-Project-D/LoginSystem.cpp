#include "LoginSystem.h"
#include <iostream>
#include <fstream>

std::string LoginSystem::getMaskedPassword() {
    std::string password;
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' is the Enter key
        if (ch == '\b' && !password.empty()) { // Handle backspace
            password.pop_back();
            std::cout << "\b \b";
        } else if (ch != '\b') {
            password.push_back(ch);
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return password;
}

LoginSystem::LoginSystem() {}

User* LoginSystem::login() {
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    password = getMaskedPassword();

    // Check all user types
    std::ifstream file;
    std::string fileUsername, filePassword;

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

    std::cout << "Invalid username or password." << std::endl;
    return nullptr;
}
