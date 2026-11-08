#include "Session.h"
#include "Timer.h"

#include <iostream>

void celebrate(const std::string& label) {
    const std::string message = label + " session complete!";
    const std::string border(message.size() + 4, '*');

    std::cout << "\n\a" << border << "\n"
              << "* " << message << " *\n"
              << border << "\n";
}

Session::Session(std::chrono::minutes work, std::chrono::minutes brk, int cycles)
    : work_(work), break_(brk), cycles_(cycles) {}

void Session::run() {
    for (int i = 0; i < cycles_; ++i) {
        Timer workTimer(std::chrono::duration_cast<std::chrono::seconds>(work_));
        workTimer.run("Work");
        celebrate("Work");

        Timer breakTimer(std::chrono::duration_cast<std::chrono::seconds>(break_));
        breakTimer.run("Break");
        celebrate("Break");
    }
}
