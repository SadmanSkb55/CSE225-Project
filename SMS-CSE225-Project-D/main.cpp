#include "User.h"
#include "LoginSystem.h"
#include "CourseCatalogue.h"
#include "University.h"
#include "OfferedCourses.h"
#include "AdvisingSystem.h"
#include "CourseEnrollmentSystem.h"
#include "signup.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <cerrno>
#include <cstring>

using namespace std;

void displayStudentMenu()
{
    cout << "Student Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Advise course" << endl;
    cout << "4. Grades" << endl;
    cout << "5. Logout" << endl;
}

void displayAdminMenu()
{
    cout << "Admin Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Add course" << endl;
    cout << "4. Remove course" << endl;
    cout << "5. Logout" << endl;
}

void displayTeacherMenu()
{
    cout << "Teacher Menu:" << endl;
    cout << "1. Show all courses" << endl;
    cout << "2. Show specific courses" << endl;
    cout << "3. Offer Course" << endl;
    cout << "4. Student grading" << endl;
    cout << "5. Logout" << endl;
}

void displaySignUpMenu()
{
    cout << "Signup as:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Admin" << endl;
    cout << "4. Back" << endl;
}

void displayTeacherMenu2()
{
    std::cout << "Teacher Menu:" << std::endl;
    std::cout << "1. Show all offered courses" << std::endl;
    std::cout << "2. Offer Course" << std::endl;
    std::cout << "3. Remove a offered course" << std::endl;
    cout << "4. Back" << endl;
}

void displayAdvisingMenu()
{
    cout << "Advising Menu:" << endl;
    cout << "1. Show all offered courses" << endl;
    cout << "2. Show offered courses with sections" << endl;
    cout << "3. Add course" << endl;
    cout << "4. Drop course" << endl;
    cout << "5. Back" << endl;
}

void gradeStudent()
{
    std::string studentName, studentID, courseCode, grade;
    bool studentFound = false;

    std::cout << "Enter student name: ";
    std::cin >> studentName;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;
    std::cout << "Enter course code: ";
    std::cin >> courseCode;
    std::cout << "Enter grade: ";
    std::cin >> grade;

    // Check if the student exists in student_info.txt
    std::ifstream studentInfoFile("studentinfo.txt");
    if (!studentInfoFile.is_open())
    {
        std::cerr << "Error opening student info file: " << std::strerror(errno) << std::endl;
        return;
    }

    std::string line;
    while (std::getline(studentInfoFile, line))
    {
        std::stringstream ss(line);
        std::string name, id, dept, major, password;

        ss >> name >> id >> dept >> major >> password;

        if (name == studentName && id == studentID)
        {
            studentFound = true;
            break;
        }
    }

    studentInfoFile.close();

    if (!studentFound)
    {
        std::cerr << "Student not found." << std::endl;
        return;
    }

    // Save the grade to grading.txt
    std::ofstream gradingFile("grading.txt", std::ios::app);
    if (!gradingFile.is_open())
    {
        std::cerr << "Error opening grading file: " << std::strerror(errno) << std::endl;
        return;
    }

    gradingFile << studentName << " " << studentID << " " << courseCode << " " << grade << std::endl;
    gradingFile.close();

    std::cout << "Grade recorded successfully." << std::endl;
}

void displayGrades(const std::string& studentName, const std::string& studentID)
{
    std::ifstream gradingFile("grading.txt");
    if (!gradingFile.is_open())
    {
        std::cerr << "Error opening grading file: " << std::strerror(errno) << std::endl;
        return;
    }

    bool found = false;
    std::string line;
    while (std::getline(gradingFile, line))
    {
        std::stringstream ss(line);
        std::string name, id, courseCode, grade;

        ss >> name >> id >> courseCode >> grade;

        if (name == studentName && id == studentID)
        {
            found = true;
            std::cout << "Course: " << courseCode << ", Grade: " << grade << std::endl;
        }
    }

    gradingFile.close();

    if (!found)
    {
        std::cout << "No grades found for " << studentName << " with ID " << studentID << "." << std::endl;
    }
}

int main()
{

    LoginSystem loginSystem;
    CourseCatalogue catalogue;
    SignUp signUp;
    University unit;
    OfferedCourses offeredCourses;
    offeredCourses.loadCourses("courses.txt");

    unit.loadCoursesFromFile("courses.txt");

    AdvisingSystem advisingSystem;
    advisingSystem.loadOfferedCourses("offeredCourses.txt");

    CourseEnrollmentSystem system;
    system.loadOfferedCourses("offeredCourses.txt");
    system.loadEnrolledCourses("enrolledCourses.txt");

    User* loggedInUser = nullptr;

    int choice;

    while (true)
    {
        cout << "----- Main Menu -----" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            User* loggedInUser = loginSystem.login();
            if (loggedInUser)
            {
                if (dynamic_cast<Student*>(loggedInUser))
                {
                    // Student specific menu
                    while (true)
                    {
                        displayStudentMenu();
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                        {
                            cout << "Showing all courses..." << endl;
                            catalogue.showAllCourses();
                            break;
                        }
                        case 2:
                        {
                            string department;
                            cout << "Enter department: ";
                            cin >> department;
                            cout << "Showing specific courses..." << endl;
                            catalogue.showSpecificCourses(department);
                            break;
                        }
                        case 3:
                        {
                            while (true)
                            {
                                displayAdvisingMenu();
                                cout << "Enter your choice: ";
                                cin >> choice;

                                switch (choice)
                                {
                                case 1:
                                {
                                    advisingSystem.printAllOfferedCourses();
                                    break;
                                }
                                case 2:
                                {
                                    advisingSystem.printAllOfferedCourses();
                                    break;
                                }
                                case 3:
                                {
                                    string studentID, courseCode, time, facultyInitial;
                                    int section;
                                    cout << "Enter your ID: ";
                                    cin >> studentID;
                                    cout << "Enter course code: ";
                                    cin >> courseCode;
                                    cout << "Enter section: ";
                                    cin >> section;
                                    cout << "Enter time: ";
                                    cin >> time;
                                    cout << "Enter faculty initials: ";
                                    cin >> facultyInitial;
                                    advisingSystem.addCourse(studentID, courseCode, section, time, facultyInitial);
                                    system.enrollStudent(studentID, courseCode, section);
                                    break;
                                }
                                case 4:
                                {
                                    string studentID, courseCode;
                                    int section;
                                    cout << "Enter your ID: ";
                                    cin >> studentID;
                                    cout << "Enter course code: ";
                                    cin >> courseCode;
                                    cout << "Enter section: ";
                                    cin >> section;
                                    advisingSystem.dropCourse(studentID, courseCode, section);
                                    system.unenrollStudent(studentID, courseCode, section);
                                    break;
                                }
                                case 5:
                                {
back_to_student_menu:
                                    break;
                                }
                                default:
                                {
                                    cout << "Invalid choice. Please try again." << endl;
                                    break;
                                }
                                }
                            }
                            break;
                        }

                        case 4:
                        {
                            cout << "Grades:" << endl;
                            string studentName, studentID, courseCode, grade;

                            cout << "Enter student name: ";
                            cin >> studentName;
                            cout << "Enter student ID: ";
                            cin >> studentID;

                            displayGrades(studentName, studentID);

                            break;
                        }
                        case 5:
                        {
                            cout << "Logging out." << endl;
                            delete loggedInUser;
                            loggedInUser = nullptr;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        }

                        if (loggedInUser == nullptr)
                            break;
                    }
                }
                else if (dynamic_cast<Teacher*>(loggedInUser))
                {
                    // Teacher specific menu
                    while (true)
                    {
                        displayTeacherMenu();
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                        {
                            cout << "Showing all courses..." << endl;
                            catalogue.showAllCourses();
                            break;
                        }
                        case 2:
                        {
                            string department;
                            cout << "Enter department: ";
                            cin >> department;
                            cout << "Showing specific courses..." << endl;
                            catalogue.showSpecificCourses(department);
                            break;
                        }
                        case 3:
                        {
                            while (true)
                            {
                                displayTeacherMenu2();
                                std::cout << "Enter your choice: ";
                                std::cin >> choice;

                                switch (choice)
                                {
                                case 1:
                                {
                                    std::cout << "Showing all courses..." << std::endl;
                                    offeredCourses.printAllCourses();
                                    break;
                                }
                                case 2:
                                {
                                    offeredCourses.offerCourse();
                                    break;
                                }
                                case 3:
                                {
                                    std::cout <<"Course and Section Drop"<< std::endl;
                                    string courseCode;
                                    int sectionToRemove;
                                    cout<<"Enter Course Code"<<endl;
                                    cin>>courseCode;
                                    cout<<"Section"<<endl;
                                    cin>>sectionToRemove;
                                    offeredCourses.removeOfferedSection(courseCode, sectionToRemove);
                                    break;
                                }
                                case 4:
                                {
                                    std::cout <<"\n"<< std::endl;
                                    break;
                                }
                                default:
                                {
                                    std::cout << "Invalid choice. Please try again." << std::endl;
                                    break;
                                }
                                }

                                if (choice == 3)
                                    break;
                            }
                            break;
                        }
                        case 4:
                        {
                            cout << "Grading a student..." << endl;
                            gradeStudent();
                            break;
                        }
                        case 5:
                        {
                            cout << "Logging out." << endl;
                            delete loggedInUser;
                            loggedInUser = nullptr;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        }

                        if (loggedInUser == nullptr)
                            break;
                    }
                }
                else if (dynamic_cast<Admin*>(loggedInUser))
                {
                    // Admin specific menu
                    while (true)
                    {
                        displayAdminMenu();
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                        {
                            cout << "Showing all courses..." << endl;
                            catalogue.showAllCourses();
                            break;
                        }
                        case 2:
                        {
                            string department;
                            cout << "Enter department: ";
                            cin >> department;
                            cout << "Showing specific courses..." << endl;
                            catalogue.showSpecificCourses(department);
                            break;
                        }
                        case 3:
                        {
                            string dept, code, name;
                            int credits;
                            cout << "Enter department, course code, and course name: ";
                            cin >> dept >> code;
                            cin.ignore();
                            getline(cin, name);
                            cout << "Enter credits: ";
                            cin >> credits;
                            catalogue.addCourse(dept, code, name, credits);
                            break;
                        }
                        case 4:
                        {
                            string department, code;
                            cout << "Enter department and course code: ";
                            cin >> department >> code;
                            catalogue.removeCourse(department, code);
                            break;
                        }
                        case 5:
                        {
                            cout << "Logging out." << endl;
                            delete loggedInUser;
                            loggedInUser = nullptr;
                            break;
                        }
                        default:
                        {
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        }

                        if (loggedInUser == nullptr)
                            break;
                    }
                }

                // After handling specific user actions, break to main menu
                break;
            }
            break;
        }
        case 2:
// Handle signup functionality
// cout << "Signup functionality not implemented yet." << endl;
            int signUpChoice;
            while (true)
            {
                displaySignUpMenu();
                cout << "Enter your choice: " << endl;
                cin >> signUpChoice;
                cin.ignore(); // To ignore the newline character left in the buffer

                switch (signUpChoice)
                {
                case 1:
                    signUp.signUpStudent();
                    break;
                case 2:
                    signUp.signUpTeacher();
                    break;
                case 3:
                    signUp.signUpAdmin();
                    break;
                case 4:
                    goto back_to_main_menu;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
back_to_main_menu:
            break;
        case 3:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    cout << "Exiting the program." << endl;
    return 0;
}
