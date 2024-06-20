#include "CourseEnrollmentSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

StudentNode::StudentNode(const string& id) : studentID(id), next(nullptr) {}

SectionNode::SectionNode(const string& code, int sec, const string& t, const string& faculty)
    : courseCode(code), section(sec), time(t), facultyInitial(faculty), enrolledCount(0), studentListHead(nullptr), next(nullptr) {}

CourseNode::CourseNode(const string& code) : courseCode(code), sectionListHead(nullptr), next(nullptr) {}

FacultyNode::FacultyNode(const string& faculty) : facultyInitial(faculty), courseListHead(nullptr), next(nullptr) {}

CourseEnrollmentSystem::CourseEnrollmentSystem() : facultyListHead(nullptr) {}

void CourseEnrollmentSystem::addStudentToSection(SectionNode* section, const string& studentID) {
    if (section->enrolledCount >= 35) {
        cout << "Enrollment failed: section is full." << endl;
        return;
    }

    StudentNode* newStudent = new StudentNode(studentID);
    newStudent->next = section->studentListHead;
    section->studentListHead = newStudent;
    section->enrolledCount++;
    cout << "Enrollment successful." << endl;

    updateEnrolledCoursesFile();
}

void CourseEnrollmentSystem::removeStudentFromSection(SectionNode* section, const string& studentID) {
    StudentNode* current = section->studentListHead;
    StudentNode* prev = nullptr;

    while (current && current->studentID != studentID) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            section->studentListHead = current->next;
        }
        delete current;
        section->enrolledCount--;
        cout << "Unenrollment successful." << endl;

        updateEnrolledCoursesFile();
    } else {
        cout << "Unenrollment failed: student not found in section." << endl;
    }
}

void CourseEnrollmentSystem::updateEnrolledCoursesFile() {
    ofstream enrolledFile("enrolledCourses.txt");
    if (!enrolledFile.is_open()) {
        cout << "Error opening enrolled courses file." << endl;
        return;
    }

    FacultyNode* faculty = facultyListHead;
    while (faculty) {
        CourseNode* course = faculty->courseListHead;
        while (course) {
            SectionNode* section = course->sectionListHead;
            while (section) {
                enrolledFile << section->courseCode << " " << section->section << " " << section->time << " " << section->facultyInitial << " " << section->enrolledCount << endl;
                section = section->next;
            }
            course = course->next;
        }
        faculty = faculty->next;
    }
    enrolledFile.close();
}

void CourseEnrollmentSystem::loadOfferedCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening offered courses file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseCode, facultyInitial;
        int section;

        ss >> courseCode >> section >> facultyInitial;

        // Find or create the faculty node
        FacultyNode* faculty = facultyListHead;
        FacultyNode* prevFaculty = nullptr;
        while (faculty && faculty->facultyInitial != facultyInitial) {
            prevFaculty = faculty;
            faculty = faculty->next;
        }
        if (!faculty) {
            faculty = new FacultyNode(facultyInitial);
            if (prevFaculty) {
                prevFaculty->next = faculty;
            } else {
                facultyListHead = faculty;
            }
        }

        // Find or create the course node
        CourseNode* course = faculty->courseListHead;
        CourseNode* prevCourse = nullptr;
        while (course && course->courseCode != courseCode) {
            prevCourse = course;
            course = course->next;
        }
        if (!course) {
            course = new CourseNode(courseCode);
            if (prevCourse) {
                prevCourse->next = course;
            } else {
                faculty->courseListHead = course;
            }
        }

        // Create the section node
        SectionNode* sectionNode = new SectionNode(courseCode, section, "", facultyInitial);
        sectionNode->next = course->sectionListHead;
        course->sectionListHead = sectionNode;
    }
    file.close();
}

void CourseEnrollmentSystem::loadEnrolledCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening enrolled courses file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseCode, time, facultyInitial;
        int section, enrolledCount;

        ss >> courseCode >> section >> time >> facultyInitial >> enrolledCount;

        // Find the corresponding section node
        FacultyNode* faculty = facultyListHead;
        while (faculty && faculty->facultyInitial != facultyInitial) {
            faculty = faculty->next;
        }
        if (!faculty) continue;

        CourseNode* course = faculty->courseListHead;
        while (course && course->courseCode != courseCode) {
            course = course->next;
        }
        if (!course) continue;

        SectionNode* sectionNode = course->sectionListHead;
        while (sectionNode && sectionNode->section != section) {
            sectionNode = sectionNode->next;
        }
        if (!sectionNode) continue;

        sectionNode->time = time;
        sectionNode->enrolledCount = enrolledCount;

        // Add the students to the section
        for (int i = 0; i < enrolledCount; i++) {
            string studentID;
            ss >> studentID;
            addStudentToSection(sectionNode, studentID);
        }
    }
    file.close();
}

void CourseEnrollmentSystem::enrollStudent(const string& studentID, const string& courseCode, int section) {
    // Find the section node
    FacultyNode* faculty = facultyListHead;
    while (faculty) {
        CourseNode* course = faculty->courseListHead;
        while (course && course->courseCode != courseCode) {
            course = course->next;
        }
        if (course) {
            SectionNode* sectionNode = course->sectionListHead;
            while (sectionNode && sectionNode->section != section) {
                sectionNode = sectionNode->next;
            }
            if (sectionNode) {
                addStudentToSection(sectionNode, studentID);
                return;
            }
        }
        faculty = faculty->next;
    }
    cout << "Enrollment failed: course or section not found." << endl;
}

void CourseEnrollmentSystem::unenrollStudent(const string& studentID, const string& courseCode, int section) {
    // Find the section node
    FacultyNode* faculty = facultyListHead;
    while (faculty) {
        CourseNode* course = faculty->courseListHead;
        while (course && course->courseCode != courseCode) {
            course = course->next;
        }
        if (course) {
            SectionNode* sectionNode = course->sectionListHead;
            while (sectionNode && sectionNode->section != section) {
                sectionNode = sectionNode->next;
            }
            if (sectionNode) {
                removeStudentFromSection(sectionNode, studentID);
                return;
            }
        }
        faculty = faculty->next;
    }
    cout << "Unenrollment failed: course or section not found." << endl;
}
