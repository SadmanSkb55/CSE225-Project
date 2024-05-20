#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "User.h"
#include <unordered_map>
#include <string>
#include <conio.h> // For _getch()

class LoginSystem {
private:
    std::string getMaskedPassword();

public:
    LoginSystem();
    User* login();
};

#endif // LOGINSYSTEM_H
