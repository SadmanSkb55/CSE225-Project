#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

/**
 * @brief The Course class represents a course with its code, name, credits, and a pointer to the next course.
 */
class Course {
public:
    string code; /**< Course code, e.g., "CSE225" */
    string name; /**< Course name, e.g., "Data Structures" */
    int credits; /**< Number of credits for the course */
    Course* next; /**< Pointer to the next course in a linked list */

    /**
     * @brief Constructor for the Course class.
     * @param c The code of the course.
     * @param n The name of the course.
     * @param cr The number of credits for the course.
     */
    Course(string c, string n, int cr);
};

/**
 * @brief The Department class represents a department that manages a linked list of courses.
 */
class Department {
public:
    Course* head; /**< Pointer to the head of the linked list of courses */

    /**
     * @brief Constructor for the Department class.
     */
    Department();

    /**
     * @brief Adds a new course to the department.
     * @param code The code of the course to add.
     * @param name The name of the course to add.
     * @param credits The number of credits for the course to add.
     */
    void addCourse(string code, string name, int credits);

    /**
     * @brief Displays all courses in the department.
     */
    void showCourses();

    /**
     * @brief Removes a course from the department.
     * @param code The code of the course to remove.
     */
    void removeCourse(string code);
};

#endif // COURSE_H
