#include "User.h"
#include "LoginSystem.h"
#include<iostream>

int main() {
    LoginSystem loginSystem;

    std::cout << "Login:" << std::endl;
    User* loggedInUser = loginSystem.login();
    if (loggedInUser) {
        loggedInUser->display();
    }

    // Clean up
    delete loggedInUser;

    return 0;
}
