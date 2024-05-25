#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string name;
    string username;
    string password;

public:
    User(const string& name, const string& password);
    virtual ~User() = default;
    string getUsername() const;
    bool setPassword(const string& newPassword);
    virtual void display() const = 0;
};

class Admin : public User {
public:
    Admin(const string& name, const string& password);
    void display() const override;
};

class Teacher : public User {
public:
    Teacher(const string& name, const string& password);
    void display() const override;
};

class Student : public User {
private:
    string id;

public:
    Student(const string& name, const string& id, const string& password);
    void display() const override;
};

#endif // USER_H
