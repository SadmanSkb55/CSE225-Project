#ifndef SIGNUP_H
#define SIGNUP_H

#include <string>

class SignUp {
public:
    void signUpStudent();
    void signUpTeacher();
    void signUpAdmin();

private:
    std::string generateUsername(const std::string& name, const std::string& type);
    bool checkUsernameExists(const std::string& username, const std::string& type);
    void saveToFile(const std::string& filename, const std::string& data);
};

#endif // SIGNUP_H

