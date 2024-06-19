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
        departments[department].addCourse(code, name, credits);
    } else {
        cout << "Department not found!" << endl;
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
        cout << "Department not found!" << endl;
    }
}

void University::removeCourse(string department, string code) {
    if (departments.find(department) != departments.end()) {
        departments[department].removeCourse(code);
    } else {
        cout << "Department not found!" << endl;
    }
}

void University::loadCoursesFromFile(string filename) {
    ifstream file(filename);
    string line, code, name, creditStr;
    int credits;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> code;
        ss.ignore();
        getline(ss, name, ' ');
        ss >> creditStr;
        credits = stoi(creditStr.substr(0, creditStr.size() - 2));

        string deptCode = code.substr(0, 3);
        addCourseToDepartment(deptCode, code, name, credits);
    }
    file.close();
}

