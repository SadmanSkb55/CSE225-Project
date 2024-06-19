#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Course.h"
#include <unordered_map>
#include <string>
using namespace std;

class University {
public:
    unordered_map<string, Department> departments;

    University();
    void addCourseToDepartment(string department, string code, string name, int credits);
    void showAllCourses();
    void showSpecificCourses(string department);
    void removeCourse(string department, string code);
    void loadCoursesFromFile(string filename);
};

#endif // UNIVERSITY_H

