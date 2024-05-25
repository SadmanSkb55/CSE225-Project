#include "SignupSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

SignupSystem::SignupSystem() {}

string SignupSystem::generateUsername(const string& name, char type) {
    string initials;
    initials.push_back(toupper(name[0])); // First initial

    for (size_t i = 1; i < name.length(); ++i) {
        if (isupper(name[i])) {
            initials.push_back(tolower(name[i])); // Other initials
        }
    }

    string username = initials + type;

    // Check for uniqueness
    if (!checkDuplicateUsername(username, type)) {
        return username;
    }

    // If username already exists, append a number to make it unique
    int count = 1;
    while (checkDuplicateUsername(username + to_string(count), type)) {
        ++count;
    }

    return username + to_string(count);
}

bool SignupSystem::checkDuplicateUsername(const string& username, char type) {
    ifstream file;
    string filename;

    if (type == 't') {
        filename = "teacher.txt";
    } else if (type == 's') {
        filename = "student.txt";
    } else if (type == 'a') {
        filename = "admin.txt";
    }

    file.open(filename);

    if (!file) {
        return false; // File doesn't exist, username is unique
    }

    string existingUsername;
    while (file >> existingUsername) {
        if (existingUsername == username) {
            file.close();
            return true; // Username already exists
        }
    }

    file.close();
    return false; // Username is unique
}

bool SignupSystem::facultySignup() {
    string name, department, major, id, password, confirmPassword;

    cout << "Enter name: ";
    getline(cin >> ws, name);

    cout << "Enter department: ";
    getline(cin >> ws, department);

    cout << "Enter major: ";
    getline(cin >> ws, major);

    cout << "Enter ID (9 digits): ";
    cin >> id;

    cout << "Enter password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match. Signup failed." << endl;
        return false;
    }

    string username = generateUsername(name, 't');

    ofstream file("teacher.txt", ios_base::app);
    file << username << " " << password << endl;
    file.close();

    ofstream infoFile("facultyinfo.txt", ios_base::app);
    infoFile << name << " " << department << " " << major << " " <<
    infoFile << id << endl;
    infoFile.close();

    cout << "Faculty signup successful. Username: " << username << endl;

    return true;
}

bool SignupSystem::studentSignup() {
    string name, id, department, major, password, confirmPassword;

    cout << "Enter name: ";
    getline(cin >> ws, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter department: ";
    getline(cin >> ws, department);

    cout << "Enter major: ";
    getline(cin >> ws, major);

    cout << "Enter password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match. Signup failed." << endl;
        return false;
    }

    ofstream file("student.txt", ios_base::app);
    file << id << " " << password << endl;
    file.close();

    ofstream infoFile("studentinfo.txt", ios_base::app);
    infoFile << name << " " << id << " " << department << " " << major << endl;
    infoFile.close();

    cout << "Student signup successful. Username: " << id << endl;

    return true;
}

bool SignupSystem::adminSignup(const string& appointedBy) {
    string name, id, department, major, password, confirmPassword;

    cout << "Enter name: ";
    getline(cin >> ws, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter department: ";
    getline(cin >> ws, department);

    cout << "Enter major: ";
    getline(cin >> ws, major);

    cout << "Enter password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match. Signup failed." << endl;
        return false;
    }

    string username = generateUsername(name, 'a');

    ofstream file("admin.txt", ios_base::app);
    file << username << " " << password << endl;
    file.close();

    ofstream infoFile("admininfo.txt", ios_base::app);
    infoFile << name << " " << id << " " << department << " " << major << " " << appointedBy << endl;
    infoFile.close();

    cout << "Admin signup successful. Username: " << username << endl;

    return true;
}

