#ifndef OFFEREDCOURSES_H
#define OFFEREDCOURSES_H

#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief Represents a class managing offered courses.
 */
class OfferedCourses {
public:
    /**
     * @brief Default constructor for OfferedCourses.
     */
    OfferedCourses();

    /**
     * @brief Loads courses from a file into the system.
     * @param filename The name of the file containing course information.
     */
    void loadCourses(const std::string& filename);

    /**
     * @brief Prints details of all offered courses.
     */
    void printAllCourses();

    /**
     * @brief Offers a new course section.
     */
    void offerCourse();

    /**
     * @brief Removes an offered section of a course.
     * @param courseCode The code of the course.
     * @param section The section number to remove.
     */
    void removeOfferedSection(const std::string& courseCode, int section);

private:
    /**
     * @brief Represents a course with its code, name, and credits.
     */
    struct Course {
        std::string code;
        std::string name;
        int credits;
    };

    /**
     * @brief Stores courses grouped by department.
     */
    std::unordered_map<std::string, std::vector<Course>> coursesByDept;

    /**
     * @brief Checks if a course code is valid.
     * @param courseCode The code of the course to validate.
     * @return True if the course code is valid, false otherwise.
     */
    bool isCourseCodeValid(const std::string& courseCode);

    /**
     * @brief Saves an offered section of a course.
     * @param courseCode The code of the course.
     * @param section The section number to offer.
     * @param time The time schedule for the section.
     * @param facultyInitial The initials of the faculty teaching the section.
     */
    void saveOfferedSection(const std::string& courseCode, int section, const std::string& time, const std::string& facultyInitial);
};

#endif // OFFEREDCOURSES_H
