#include "User.h"
#include <iostream>

using namespace std;

User::User(const string& name, const string& password)
    : name(name), password(password) {}

string User::getUsername() const {
    return username;
}

bool User::setPassword(const string& newPassword) {
    // Add password validation logic if needed
    password = newPassword;
    return true; // Password successfully set
}

Admin::Admin(const string& name, const string& password)
    : User(name, password) {}

void Admin::display() const {
    cout << "Admin: " << name << endl;
}

Teacher::Teacher(const string& name, const string& password)
    : User(name, password) {}

void Teacher::display() const {
    cout << "Teacher: " << name << endl;
}

Student::Student(const string& name, const string& id, const string& password)
    : User(name, password), id(id) {}

void Student::display() const {
    cout << "Student: " << name << " (ID: " << id << ")" << endl;
}
