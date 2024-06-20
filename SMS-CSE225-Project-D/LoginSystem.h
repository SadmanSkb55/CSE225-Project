#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "User.h"
#include <string>
#include <conio.h> // For _getch()

/**
 * @brief Represents a Login System for user authentication.
 */
class LoginSystem {
private:
    /**
     * @brief Gets a masked password from user input.
     * @return The masked password input by the user.
     */
    std::string getMaskedPassword();

public:
    /**
     * @brief Default constructor for the LoginSystem class.
     */
    LoginSystem();

    /**
     * @brief Performs user login process.
     * @return A pointer to the User object if login is successful, nullptr otherwise.
     */
    User* login();
};

#endif // LOGINSYSTEM_H
