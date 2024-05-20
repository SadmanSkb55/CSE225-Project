#include "Captcha.h"

Captcha::Captcha() {
    srand(static_cast<unsigned>(time(0)));
}

int Captcha::generateCaptcha() {
    value = rand() % 9000 + 1000; // Generate a 4-digit number
    return value;
}

int Captcha::getCaptcha() {
    return value;
}

void Captcha::displayCaptcha() {
    int captcha = generateCaptcha();
    std::cout << "Captcha: " << captcha << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "\rCaptcha:     " << std::flush; // Clear the captcha
}
