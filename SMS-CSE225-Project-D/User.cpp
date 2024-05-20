#include "User.h"
#include <iostream>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

std::string User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password) {}

void Admin::display() const {
    std::cout << "Admin: " << username << std::endl;
}

Teacher::Teacher(const std::string& username, const std::string& password)
    : User(username, password) {}

void Teacher::display() const {
    std::cout << "Teacher: " << username << std::endl;
}

Student::Student(const std::string& username, const std::string& password)
    : User(username, password) {}

void Student::display() const {
    std::cout << "Student: " << username << std::endl;
}
