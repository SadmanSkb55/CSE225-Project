#include "AdvisingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void AdvisingSystem::loadOfferedCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening offered courses file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseCode, time, facultyInitial;
        int section;

        ss >> courseCode >> section >> time >> facultyInitial;

        offeredCourses.push_back({courseCode, section, time, facultyInitial});
    }
    file.close();
}

void AdvisingSystem::printAllOfferedCourses() const {
    for (const auto& course : offeredCourses) {
        cout << course.courseCode << " Section: " << course.section << " Time: " << course.time << " Faculty: " << course.facultyInitial << endl;
    }
}

bool AdvisingSystem::isCourseOffered(const string& courseCode, int section) const {
    for (const auto& course : offeredCourses) {
        if (course.courseCode == courseCode && course.section == section) {
            return true;
        }
    }
    return false;
}

void AdvisingSystem::addCourse(const string& studentID, const string& courseCode, int section, const string& time, const string& facultyInitial) {
    if (isCourseOffered(courseCode, section)) {
        saveStudentCourse(studentID, courseCode, section);
        cout << "Course added successfully." << endl;
    } else {
        cout << "Course or section not offered." << endl;
    }
}

void AdvisingSystem::dropCourse(const string& studentID, const string& courseCode, int section) {
    if (isCourseOffered(courseCode, section)) {
        removeStudentCourse(studentID, courseCode, section);
        cout << "Course dropped successfully." << endl;
    } else {
        cout << "Course or section not offered." << endl;
    }
}

void AdvisingSystem::saveStudentCourse(const string& studentID, const string& courseCode, int section) {
    ofstream file(studentID + "_courses.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening student courses file." << endl;
        return;
    }
    file << courseCode << " " << section <<" "<<studentID<< endl;
    file.close();

    ofstream enrolledFile("enrolledCourses.txt", ios::app);
    if (!enrolledFile.is_open()) {
        cout << "Error opening enrolled courses file." << endl;
        return;
    }
    enrolledFile << courseCode << " " << section << " " << studentID << endl;
    enrolledFile.close();
}

void AdvisingSystem::removeStudentCourse(const string& studentID, const string& courseCode, int section) {
    ifstream inputFile(studentID + "_courses.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening student courses file." << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string code;
        int sec;
        ss >> code >> sec;
        if (code == courseCode && sec == section) {
            // Skip this line (remove from output)
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile(studentID + "_courses.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening student courses file for writing." << endl;
        return;
    }

    for (const auto& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();
}
