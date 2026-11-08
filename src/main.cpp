#include "Session.h"

#include <chrono>
#include <iostream>
#include <string>


std::chrono::minutes getDuration(const std::string& label) {

    int workMinutes;
    std::cout<<label;
    std::cin>>workMinutes;
    return std::chrono::minutes(workMinutes);

}

int main() {
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
