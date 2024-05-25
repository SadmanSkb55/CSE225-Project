#ifndef SIGNUPSYSTEM_H
#define SIGNUPSYSTEM_H

#include "User.h"
#include <string>

using namespace std;

class SignupSystem {
private:
    string generateUsername(const string& name, char type);
    bool checkDuplicateUsername(const string& username, char type);

public:
    SignupSystem();
    bool facultySignup();
    bool studentSignup();
    bool adminSignup(const string& appointedBy);
};

#endif // SIGNUPSYSTEM_H

