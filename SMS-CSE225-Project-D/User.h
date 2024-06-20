#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

/**
 * @brief Base class representing a User with username and password.
 */
class User {
protected:
    string username; ///< The username of the user.
    string password; ///< The password of the user.

public:
    /**
     * @brief Constructor to initialize a User with username and password.
     * @param username The username of the user.
     * @param password The password of the user.
     */
    User(const string& username, const string& password);

    /**
     * @brief Virtual destructor for User class.
     */
    virtual ~User() = default;

    /**
     * @brief Getter method for retrieving the username.
     * @return The username of the user.
     */
    string getUsername() const;

    /**
     * @brief Method to check if a provided password matches the user's password.
     * @param password The password to check against the user's password.
     * @return True if the provided password matches the user's password, false otherwise.
     */
    bool checkPassword(const string& password) const;

    /**
     * @brief Pure virtual method to display information about the user.
     */
    virtual void display() const = 0; // Pure virtual function
};

/**
 * @brief Derived class representing an Admin user.
 */
class Admin : public User {
public:
    /**
     * @brief Constructor to initialize an Admin user with username and password.
     * @param username The username of the Admin.
     * @param password The password of the Admin.
     */
    Admin(const string& username, const string& password);

    /**
     * @brief Method to display information specific to the Admin user.
     */
    void display() const override;
};

/**
 * @brief Derived class representing a Teacher user.
 */
class Teacher : public User {
public:
    /**
     * @brief Constructor to initialize a Teacher user with username and password.
     * @param username The username of the Teacher.
     * @param password The password of the Teacher.
     */
    Teacher(const string& username, const string& password);

    /**
     * @brief Method to display information specific to the Teacher user.
     */
    void display() const override;
};

/**
 * @brief Derived class representing a Student user.
 */
class Student : public User {
public:
    /**
     * @brief Constructor to initialize a Student user with username and password.
     * @param username The username of the Student.
     * @param password The password of the Student.
     */
    Student(const string& username, const string& password);

    /**
     * @brief Method to display information specific to the Student user.
     */
    void display() const override;
};

#endif // USER_H
