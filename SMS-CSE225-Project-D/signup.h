#ifndef SIGNUP_H
#define SIGNUP_H

#include <string>

/**
 * @brief Class for signing up users (students, teachers, admins).
 */
class SignUp {
public:
    /**
     * @brief Signs up a student.
     */
    void signUpStudent();

    /**
     * @brief Signs up a teacher.
     */
    void signUpTeacher();

    /**
     * @brief Signs up an admin.
     */
    void signUpAdmin();

private:
    /**
     * @brief Generates a username based on name and type.
     * @param name The name of the user.
     * @param type The type of user (student, teacher, admin).
     * @return The generated username.
     */
    std::string generateUsername(const std::string& name, const std::string& type);

    /**
     * @brief Checks if a username already exists.
     * @param username The username to check.
     * @param type The type of user (student, teacher, admin).
     * @return True if the username exists, false otherwise.
     */
    bool checkUsernameExists(const std::string& username, const std::string& type);

    /**
     * @brief Saves data to a file.
     * @param filename The name of the file to save to.
     * @param data The data to save.
     */
    void saveToFile(const std::string& filename, const std::string& data);
};

#endif // SIGNUP_H
