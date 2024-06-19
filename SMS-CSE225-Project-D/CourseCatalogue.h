#ifndef COURSE_CATALOGUE_H
#define COURSE_CATALOGUE_H

#include "University.h"
#include <string>

class CourseCatalogue {
private:
    University uni;

public:
    CourseCatalogue();
    void loadCoursesFromFile(std::string filename);
    void showAllCourses();
    void showSpecificCourses(std::string department);
    void addCourse(std::string department, std::string code, std::string name, int credits);
    void removeCourse(std::string department, std::string code);
    void run();
};

#endif // COURSE_CATALOGUE_H
