#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(string c, string n, int cr) : code(c), name(n), credits(cr), next(nullptr) {}

Department::Department() : head(nullptr) {}

void Department::addCourse(string code, string name, int credits) {
    Course* newCourse = new Course(code, name, credits);
    newCourse->next = head;
    head = newCourse;
    cout << "Added course: " << code << ", " << name << ", " << credits << " credits" << endl;
}

void Department::showCourses() {
    Course* current = head;
    if (!current) {
        cout << "No courses available." << endl;
    }
    while (current) {
        cout << current->code << " " << current->name << " " << current->credits << "cr" << endl;
        current = current->next;
    }
}

void Department::removeCourse(string code) {
    Course* current = head;
    Course* previous = nullptr;
    while (current) {
        if (current->code == code) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Removed course: " << code << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Course not found: " << code << endl;
}
