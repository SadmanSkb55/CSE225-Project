#include "SignUp.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string GREEN_TEXT = "\033[32m";
const string RESET_TEXT = "\033[0m";

void SignUp::signUpStudent() {
    string name, id, department, major, password, confirmPassword;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, department);
    cout << "Enter Major: ";
    getline(cin, major);
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match." << endl;
        return;
    }

    string username = id; // Username for student is their ID

    // Save to studentinfo.txt
    stringstream studentInfo;
    studentInfo << name << " " << id << " " << department << " " << major << " " << password << "\n";
    saveToFile("studentinfo.txt", studentInfo.str());

    // Save to student.txt
    stringstream student;
    student << username << " " << password << "\n";
    saveToFile("student.txt", student.str());

    cout << GREEN_TEXT << "Student signed up successfully!" << RESET_TEXT << endl;
}

void SignUp::signUpTeacher() {
    string name, department, major, id, password, confirmPassword;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Department: ";
cin.ignore();
    getline(cin, department);
    cout << "Enter Major: ";
    getline(cin, major);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match." << endl;
        return;
    }

    string username = generateUsername(name, "teacher");

    // Save to teacherinfo.txt
    stringstream teacherInfo;
    teacherInfo << name << " " << department << " " << major << " " << id << " " << password << "\n";
    saveToFile("teacherinfo.txt", teacherInfo.str());

    // Save to teacher.txt
    stringstream teacher;
    teacher << username << " " << password << "\n";
    saveToFile("teacher.txt", teacher.str());

    cout << GREEN_TEXT << "Teacher signed up successfully!" << RESET_TEXT << endl;
}

void SignUp::signUpAdmin() {
    string name, department, major, id, password, confirmPassword, appointingAdminUsername, appointingAdminPassword;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, department);
    cout << "Enter Major: ";
    getline(cin, major);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match." << endl;
        return;
    }

    cout << "Enter the appointing Admin's Username: ";
    cin >> appointingAdminUsername;
    cout << "Enter the appointing Admin's Password: ";
    cin >> appointingAdminPassword;

    // Verify appointing admin credentials
    ifstream adminFile("admin.txt");
    string adminUsername, adminPassword;
    bool isValidAdmin = false;

    while (adminFile >> adminUsername >> adminPassword) {
        if (adminUsername == appointingAdminUsername && adminPassword == appointingAdminPassword) {
            isValidAdmin = true;
            break;
        }
    }
    adminFile.close();

    if (!isValidAdmin) {
        cout << "Invalid appointing Admin credentials." << endl;
        return;
    }

    string username = generateUsername(name, "admin");

    // Save to admininfo.txt
    stringstream adminInfo;
    adminInfo << name << " " << department << " " << major << " " << id << " " << password << "\n";
    saveToFile("admininfo.txt", adminInfo.str());

    // Save to admin.txt
    stringstream admin;
    admin << username << " " << password << "\n";
    saveToFile("admin.txt", admin.str());

    cout << GREEN_TEXT << "Admin signed up successfully!" << RESET_TEXT << endl;
}

string SignUp::generateUsername(const string& name, const string& type) {
    stringstream initials;
    istringstream iss(name);
    string word;

    while (iss >> word) {
        initials << (char)toupper(word[0]);
    }

    string username = initials.str();

    if (type == "admin") {
        username += "adm";
    }

    int suffix = 1;
    string baseUsername = username;

    while (checkUsernameExists(username, type)) {
        username = baseUsername + to_string(suffix++);
    }

    return username;
}

bool SignUp::checkUsernameExists(const string& username, const string& type) {
    string filename;

    if (type == "student") {
        filename = "student.txt";
    } else if (type == "teacher") {
        filename = "teacher.txt";
    } else if (type == "admin") {
        filename = "admin.txt";
    }

    ifstream file(filename);
    string fileUsername, filePassword;

    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username) {
            return true;
        }
    }

    return false;
}

void SignUp::saveToFile(const string& filename, const string& data) {
    ofstream file(filename, ios::app);
    file << data;
    file.close();
}

