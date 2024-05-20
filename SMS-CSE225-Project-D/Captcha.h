#ifndef CAPTCHA_H
#define CAPTCHA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class Captcha {
private:
    int value;
    int generateCaptcha();

public:
    Captcha();
    int getCaptcha();
    void displayCaptcha();
};

#endif // CAPTCHA_H
