#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Course.h"
#include <unordered_map>
#include <string>

/**
 * @brief Class representing a University with departments and courses.
 */
class University {
public:
    std::unordered_map<std::string, Department> departments; ///< Map of departments in the university.

    /**
     * @brief Default constructor for University class.
     */
    University();

    /**
     * @brief Adds a course to a specific department.
     * @param department The department to add the course to.
     * @param code The code of the course.
     * @param name The name of the course.
     * @param credits The credits of the course.
     */
    void addCourseToDepartment(std::string department, std::string code, std::string name, int credits);

    /**
     * @brief Displays all courses offered by all departments.
     */
    void showAllCourses();

    /**
     * @brief Displays courses offered by a specific department.
     * @param department The department to display courses from.
     */
    void showSpecificCourses(std::string department);

    /**
     * @brief Removes a course from a specific department.
     * @param department The department to remove the course from.
     * @param code The code of the course to remove.
     */
    void removeCourse(std::string department, std::string code);

    /**
     * @brief Loads courses from a file into the university system.
     * @param filename The name of the file containing course data.
     */
    void loadCoursesFromFile(std::string filename);
};

#endif // UNIVERSITY_H
