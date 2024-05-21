#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User(const string& username, const string& password);
    string getUsername() const;
    bool checkPassword(const string& password) const;
    virtual void display() const = 0;
};

class Admin : public User {
public:
    Admin(const string& username, const string& password);
    void display() const override;
};

class Teacher : public User {
public:
    Teacher(const string& username, const string& password);
    void display() const override;
};

class Student : public User {
public:
    Student(const string& username, const string& password);
    void display() const override;
};

#endif // USER_H
