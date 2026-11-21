#include "Session.h"
#include "Timer.h"

#include <iostream>

namespace {
// Same ANSI-escape caveat as Timer.cpp: needs a VT100-capable terminal.
const std::string kWorkColor = "\033[91m";   // bright red
const std::string kBreakColor = "\033[92m";  // bright green
const std::string kBannerColor = "\033[93m"; // yellow
const std::string kColorReset = "\033[0m";
} // namespace

void celebrate(const std::string& label) {
    const std::string message = label + " session complete!";
    const std::string border(message.size() + 4, '*');

    std::cout << kBannerColor;
    std::cout << "\n\a" << border << "\n"
              << "* " << message << " *\n"
              << border << "\n";
    std::cout << kColorReset;
}

Session::Session(std::chrono::minutes work, std::chrono::minutes brk, int cycles)
    : work_(work), break_(brk), cycles_(cycles) {}

void Session::run() {
    for (int i = 0; i < cycles_; ++i) {
        Timer workTimer(std::chrono::duration_cast<std::chrono::seconds>(work_));
        workTimer.run(kWorkColor + "Work" + kColorReset);
        celebrate("Work");

        Timer breakTimer(std::chrono::duration_cast<std::chrono::seconds>(break_));
        breakTimer.run(kBreakColor + "Break" + kColorReset);
        celebrate("Break");
    }
}
