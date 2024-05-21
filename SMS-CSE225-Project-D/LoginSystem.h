#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "User.h"
#include <string>
#include <conio.h> // For _getch()

using namespace std;

class LoginSystem {
private:
    string getMaskedPassword();

public:
    LoginSystem();
    User* login();
};

#endif // LOGINSYSTEM_H
