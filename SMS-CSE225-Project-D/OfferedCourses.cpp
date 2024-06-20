#include "OfferedCourses.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

OfferedCourses::OfferedCourses() {}

void OfferedCourses::loadCourses(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening courses file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string deptCode, courseCode, courseName;
        int credits;

        ss >> deptCode >> courseCode;
        ss.ignore(); // Ignore the space
        std::getline(ss, courseName, ',');
        ss >> credits;

        Course course = {courseCode, courseName, credits};
        coursesByDept[deptCode].push_back(course);
    }
    file.close();
}

void OfferedCourses::printAllCourses() {
    for (const auto& dept : coursesByDept) {
        std::cout << dept.first << " Courses:" << std::endl;
        for (const auto& course : dept.second) {
            std::cout << course.code << " " << course.name << " " << course.credits << "cr" << std::endl;
        }
    }
    std::ifstream file("courses.txt");
    if (!file.is_open()) {
        std::cout << "Error opening courses file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}

void OfferedCourses::offerCourse() {
    std::cout << "Offer a course..." << std::endl;

    // Show all available courses
    std::cout << "Available courses:" << std::endl;
    printAllCourses(); // Function to print all available courses

    std::string courseCode;
    std::cout << "Enter course code to offer: ";
    std::cin >> courseCode;

    // Check if the course code is valid
    if (!isCourseCodeValid(courseCode)) {
        std::cout << "Course code not found." << std::endl;
        return;
    }

    int numSections;
    string facIn;
    std::cout<<"Enter Faculty Initial"<<endl;
    cin>>facIn;
    std::cout << "Enter number of sections (1 to 3): ";
    std::cin >> numSections;

    if (numSections < 1 || numSections > 3) {
        std::cout << "Invalid number of sections." << std::endl;
        return;
    }

    for (int i = 1; i <= numSections; ++i) {
        int section;
        std::string time;

        std::cout << "Enter section number " << i << ": ";
        std::cin >> section;

        std::cout << "Enter time for section " << section << " (HH:MM): ";
        std::cin >> time;

        // Assuming faculty initial is not needed as it's typically associated with the teacher's ID

        // Save offered course section
        saveOfferedSection(courseCode, section, time, facIn); // Replace "Faculty" with actual faculty initial or ID if needed
    }
}

bool OfferedCourses::isCourseCodeValid(const std::string& courseCode) {
    /*for (const auto& dept : coursesByDept) {
        for (const auto& course : dept.second) {
            if (course.code == courseCode) {
                return true;
            }
        }
    }
    return false;*/
    std::ifstream file("courses.txt");
    if (!file.is_open()) {
        std::cout << "Error opening courses file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string code;
        ss >> code;
        if (code == courseCode) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void OfferedCourses::saveOfferedSection(const std::string& courseCode, int section, const std::string& time, const std::string& facultyInitial) {
    std::ofstream file("offeredCourses.txt", std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error opening offered courses file." << std::endl;
        return;
    }
    file << courseCode << " " << section << " " << time << " " << facultyInitial << std::endl;
    file.close();
}

void OfferedCourses::removeOfferedSection(const std::string& courseCode, int section) {
    std::ifstream inputFile("offeredCourses.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error opening offered courses file." << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string code;
        int sec;
        ss >> code >> sec;
        if (code == courseCode && sec == section) {
            // Skip this line (remove from output)
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();

    std::ofstream outputFile("offeredCourses.txt");
    if (!outputFile.is_open()) {
        std::cout << "Error opening offered courses file for writing." << std::endl;
        return;
    }

    for (const auto& line : lines) {
        outputFile << line << std::endl;
    }
    outputFile.close();

    std::cout << "Removed section " << section << " of course " << courseCode << " from offered courses." << std::endl;
}
