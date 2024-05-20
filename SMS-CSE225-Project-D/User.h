#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& username, const std::string& password);
    std::string getUsername() const;
    bool checkPassword(const std::string& password) const;
    virtual void display() const = 0;
};

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);
    void display() const override;
};

class Teacher : public User {
public:
    Teacher(const std::string& username, const std::string& password);
    void display() const override;
};

class Student : public User {
public:
    Student(const std::string& username, const std::string& password);
    void display() const override;
};

#endif // USER_H
