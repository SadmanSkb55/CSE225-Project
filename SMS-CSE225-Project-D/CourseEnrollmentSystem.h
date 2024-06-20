#ifndef COURSEENROLLMENTSYSTEM_H
#define COURSEENROLLMENTSYSTEM_H

#include <string>

/**
 * @brief Represents a node in the student linked list.
 */
class StudentNode {
public:
    std::string studentID;  /**< Student ID */
    StudentNode* next;      /**< Pointer to the next student node */

    /**
     * @brief Constructor to initialize a StudentNode.
     * @param id The student ID.
     */
    StudentNode(const std::string& id);
};

/**
 * @brief Represents a node in the section linked list.
 */
class SectionNode {
public:
    std::string courseCode;       /**< Course code */
    int section;                  /**< Section number */
    std::string time;             /**< Class time */
    std::string facultyInitial;   /**< Initials of faculty teaching */
    int enrolledCount;            /**< Number of enrolled students */
    StudentNode* studentListHead; /**< Head of the student list enrolled in this section */
    SectionNode* next;            /**< Pointer to the next section node */

    /**
     * @brief Constructor to initialize a SectionNode.
     * @param code The course code.
     * @param sec The section number.
     * @param t The class time.
     * @param faculty The faculty initials.
     */
    SectionNode(const std::string& code, int sec, const std::string& t, const std::string& faculty);
};

/**
 * @brief Represents a node in the course linked list.
 */
class CourseNode {
public:
    std::string courseCode;     /**< Course code */
    SectionNode* sectionListHead; /**< Head of the section list for this course */
    CourseNode* next;           /**< Pointer to the next course node */

    /**
     * @brief Constructor to initialize a CourseNode.
     * @param code The course code.
     */
    CourseNode(const std::string& code);
};

/**
 * @brief Represents a node in the faculty linked list.
 */
class FacultyNode {
public:
    std::string facultyInitial; /**< Faculty initials */
    CourseNode* courseListHead; /**< Head of the course list taught by this faculty */
    FacultyNode* next;          /**< Pointer to the next faculty node */

    /**
     * @brief Constructor to initialize a FacultyNode.
     * @param faculty The faculty initials.
     */
    FacultyNode(const std::string& faculty);
};

/**
 * @brief Manages course enrollment and student registration in a university system.
 */
class CourseEnrollmentSystem {
private:
    FacultyNode* facultyListHead; /**< Head of the faculty linked list */

    /**
     * @brief Adds a student to the student list of a section.
     * @param section Pointer to the SectionNode where the student will be added.
     * @param studentID The ID of the student to add.
     */
    void addStudentToSection(SectionNode* section, const std::string& studentID);

    /**
     * @brief Removes a student from the student list of a section.
     * @param section Pointer to the SectionNode from which the student will be removed.
     * @param studentID The ID of the student to remove.
     */
    void removeStudentFromSection(SectionNode* section, const std::string& studentID);

    /**
     * @brief Updates the enrolled courses file after changes in enrollment.
     */
    void updateEnrolledCoursesFile();

public:
    /**
     * @brief Default constructor for the CourseEnrollmentSystem class.
     */
    CourseEnrollmentSystem();

    /**
     * @brief Loads offered courses from a file into the system.
     * @param filename The name of the file containing offered courses.
     */
    void loadOfferedCourses(const std::string& filename);

    /**
     * @brief Loads enrolled courses from a file into the system.
     * @param filename The name of the file containing enrolled courses.
     */
    void loadEnrolledCourses(const std::string& filename);

    /**
     * @brief Enrolls a student in a specific course section.
     * @param studentID The ID of the student to enroll.
     * @param courseCode The code of the course to enroll in.
     * @param section The section number of the course to enroll in.
     */
    void enrollStudent(const std::string& studentID, const std::string& courseCode, int section);

    /**
     * @brief Unenrolls a student from a specific course section.
     * @param studentID The ID of the student to unenroll.
     * @param courseCode The code of the course to unenroll from.
     * @param section The section number of the course to unenroll from.
     */
    void unenrollStudent(const std::string& studentID, const std::string& courseCode, int section);
};

#endif // COURSEENROLLMENTSYSTEM_H
