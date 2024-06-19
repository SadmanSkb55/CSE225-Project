#include "CourseCatalogue.h"
#include <iostream>

CourseCatalogue::CourseCatalogue() {
    // Initialize the University object (if necessary)
}

void CourseCatalogue::loadCoursesFromFile(std::string filename) {
    uni.loadCoursesFromFile(filename);
}

void CourseCatalogue::showAllCourses() {
    uni.showAllCourses();
}

void CourseCatalogue::showSpecificCourses(std::string department) {
    uni.showSpecificCourses(department);
}

void CourseCatalogue::addCourse(std::string department, std::string code, std::string name, int credits) {
    uni.addCourseToDepartment(department, code, name, credits);
}

void CourseCatalogue::removeCourse(std::string department, std::string code) {
    uni.removeCourse(department, code);
}

void CourseCatalogue::run() {
    int choice;
    std::string department, code, name;
    int credits;

    do {
        std::cout << "1. Show All Courses\n"
                     "2. Show Specific Department Courses\n"
                     "3. Add Course\n"
                     "4. Remove Course\n"
                     "5. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showAllCourses();
            break;
        case 2:
            std::cout << "Enter Department Code: ";
            std::cin >> department;
            showSpecificCourses(department);
            break;
        case 3:
            std::cout << "Enter Department Code: ";
            std::cin >> department;
            std::cout << "Enter Course Code: ";
            std::cin >> code;
            std::cout << "Enter Course Name: ";
            std::cin.ignore(); // to consume the newline character left in the buffer
            std::getline(std::cin, name);
            std::cout << "Enter Credits: ";
            std::cin >> credits;
            addCourse(department, code, name, credits);
            break;
        case 4:
            std::cout << "Enter Department Code: ";
            std::cin >> department;
            std::cout << "Enter Course Code: ";
            std::cin >> code;
            removeCourse(department, code);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 5);
}
