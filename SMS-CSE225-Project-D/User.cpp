#include "User.h"
#include <iostream>

using namespace std;

const string GREEN_TEXT = "\033[32m";
const string RESET_TEXT = "\033[0m";

User::User(const string& username, const string& password)
    : username(username), password(password) {}

string User::getUsername() const {
    return username;
}

bool User::checkPassword(const string& password) const {
    return this->password == password;
}

Admin::Admin(const string& username, const string& password)
    : User(username, password) {}

void Admin::display() const {
    cout << GREEN_TEXT << "Admin: " << username << RESET_TEXT << endl;
}

Teacher::Teacher(const string& username, const string& password)
    : User(username, password) {}

void Teacher::display() const {
    cout << GREEN_TEXT << "Teacher: " << username << RESET_TEXT << endl;
}

Student::Student(const string& username, const string& password)
    : User(username, password) {}

void Student::display() const {
    cout << GREEN_TEXT << "Student: " << username << RESET_TEXT << endl;
}
