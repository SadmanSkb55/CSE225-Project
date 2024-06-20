#include "University.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

University::University() {
    // Initialize departments
    departments["ARC"];
    departments["CSE"];
    departments["EEE"];
    departments["LAW"];
    departments["MAT"];
    departments["ENG"];
    departments["GED"];
}

void University::addCourseToDepartment(string department, string code, string name, int credits) {
    if (departments.find(department) != departments.end()) {
        cout << "Adding course to department: " << department << endl;
        departments[department].addCourse(code, name, credits);
    } else {
        //cout << "Department not found: " << department << endl;
    }
}

void University::showAllCourses() {
    for (auto& dept : departments) {
        cout << dept.first << " Courses:" << endl;
        dept.second.showCourses();
        cout << endl;
    }
}

void University::showSpecificCourses(string department) {
    if (departments.find(department) != departments.end()) {
        cout << department << " Courses:" << endl;
        departments[department].showCourses();
    } else {
      //  cout << "Department not found: " << department << endl;
    }
}

void University::removeCourse(string department, string code) {
    if (departments.find(department) != departments.end()) {
        departments[department].removeCourse(code);
    } else {
        //cout << "Department not found: " << department << endl;
    }
}

void University::loadCoursesFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string deptCode, code, name, creditStr;
        int credits;

        ss >> deptCode >> code;
        if (!ss) {
           // std::cout << "Error reading course and department code from line: " << line << std::endl;
            continue;
        }
        ss.ignore(); // Skip the space
        std::getline(ss, name, ' ');
        if (!ss) {
            //std::cout << "Error reading course name from line: " << line << std::endl;
            continue;
        }
        ss >> creditStr;
        if (!ss) {
            //std::cout << "Error reading course credits from line: " << line << std::endl;
            continue;
        }

        // Parse credits from creditStr
        try {
            // Check if creditStr ends with "cr"
            if (creditStr.size() >= 2 && creditStr.substr(creditStr.size() - 2) == "cr") {
                credits = std::stoi(creditStr.substr(0, creditStr.size() - 2));
            } else {
                throw std::invalid_argument("Invalid credit format");
            }
        } catch (std::invalid_argument& e) {
           // std::cout << "Invalid credit format on line: " << line << std::endl;
            continue;
        }

        addCourseToDepartment(deptCode, code, name, credits);
    }
    file.close();
}
