#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
public:
    string code;
    string name;
    int credits;
    Course* next;

    Course(string c, string n, int cr);
};

class Department {
public:
    Course* head;

    Department();
    void addCourse(string code, string name, int credits);
    void showCourses();
    void removeCourse(string code);
};

#endif // COURSE_H

