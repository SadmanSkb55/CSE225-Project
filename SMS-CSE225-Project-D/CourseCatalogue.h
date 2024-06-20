#ifndef COURSE_CATALOGUE_H
#define COURSE_CATALOGUE_H

#include "University.h"
#include <string>

/**
 * @brief The CourseCatalogue class manages a catalog of courses within a university.
 */
class CourseCatalogue {
private:
    University uni; /**< The University object associated with the catalogue. */

public:
    /**
     * @brief Default constructor for the CourseCatalogue class.
     */
    CourseCatalogue();

    /**
     * @brief Loads course information from a file into the catalogue.
     * @param filename The name of the file containing course information.
     */
    void loadCoursesFromFile(std::string filename);

    /**
     * @brief Displays information about all courses in the catalogue.
     */
    void showAllCourses();

    /**
     * @brief Displays information about courses in a specific department.
     * @param department The department name for which courses should be displayed.
     */
    void showSpecificCourses(std::string department);

    /**
     * @brief Adds a new course to the catalogue under a specific department.
     * @param department The department name to which the course belongs.
     * @param code The code of the new course.
     * @param name The name of the new course.
     * @param credits The number of credits for the new course.
     */
    void addCourse(std::string department, std::string code, std::string name, int credits);

    /**
     * @brief Removes a course from the catalogue under a specific department.
     * @param department The department name from which the course should be removed.
     * @param code The code of the course to remove.
     */
    void removeCourse(std::string department, std::string code);

    /**
     * @brief Runs the course catalogue application.
     * This function typically includes a loop to interactively manage the course catalogue.
     */
    void run();
};

#endif // COURSE_CATALOGUE_H
