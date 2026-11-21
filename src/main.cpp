#include "Session.h"

#include <chrono>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

std::chrono::minutes getDuration(const std::string& label) {

    int workMinutes;
    std::cout<<label;
    std::cin>>workMinutes;
    return std::chrono::minutes(workMinutes);

}

int main() {
#ifdef _WIN32
    // Without this, Windows consoles decode the UTF-8 bytes of the progress
    // bar's block character one byte at a time using the legacy OEM/ANSI
    // codepage, producing mojibake instead of a solid block.
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::cout << "=== Pomodoro CLI ===\n";

    std::chrono::minutes workMinutes = getDuration("Work duration (minutes): ");
    std::chrono::minutes breakMinutes  = getDuration("Break duration (minutes): ");

    int cycles;
    std::cout << "Number of cycles: ";
    std::cin >> cycles;

    Session session(std::chrono::minutes(workMinutes), std::chrono::minutes(breakMinutes), cycles);
    session.run();

    return 0;
}
