#ifndef ADVISING_SYSTEM_H
#define ADVISING_SYSTEM_H

#include <string>
#include <vector>

/**
 * @brief The AdvisingSystem class handles operations related to course advising.
 */
class AdvisingSystem {
public:
    /**
     * @brief The OfferedCourse struct represents a course offered in the system.
     */
    struct OfferedCourse {
        std::string courseCode; /**< Course code, e.g., "CSE225" */
        int section; /**< Course section number */
        std::string time; /**< Time slot of the course */
        std::string facultyInitial; /**< Initial of the faculty teaching the course */
    };

    /**
     * @brief Loads offered courses from a file into the system.
     * @param filename The name of the file containing offered courses.
     */
    void loadOfferedCourses(const std::string& filename);

    /**
     * @brief Prints all offered courses to the standard output.
     */
    void printAllOfferedCourses() const;

    /**
     * @brief Adds a course to a student's schedule.
     * @param studentID The ID of the student.
     * @param courseCode The code of the course to add.
     * @param section The section number of the course.
     * @param time The time slot of the course.
     * @param facultyInitial The initial of the faculty teaching the course.
     */
    void addCourse(const std::string& studentID, const std::string& courseCode, int section,
                   const std::string& time, const std::string& facultyInitial);

    /**
     * @brief Drops a course from a student's schedule.
     * @param studentID The ID of the student.
     * @param courseCode The code of the course to drop.
     * @param section The section number of the course.
     */
    void dropCourse(const std::string& studentID, const std::string& courseCode, int section);

    /**
     * @brief Checks if a course with a specific section is offered.
     * @param courseCode The code of the course.
     * @param section The section number of the course.
     * @return true if the course is offered, false otherwise.
     */
    bool isCourseOffered(const std::string& courseCode, int section) const;

private:
    std::vector<OfferedCourse> offeredCourses; /**< Vector storing all offered courses. */

    /**
     * @brief Saves a course to a student's course file.
     * @param studentID The ID of the student.
     * @param courseCode The code of the course to save.
     * @param section The section number of the course.
     */
    void saveStudentCourse(const std::string& studentID, const std::string& courseCode, int section);

    /**
     * @brief Removes a course from a student's course file.
     * @param studentID The ID of the student.
     * @param courseCode The code of the course to remove.
     * @param section The section number of the course.
     */
    void removeStudentCourse(const std::string& studentID, const std::string& courseCode, int section);
};

#endif // ADVISING_SYSTEM_H
