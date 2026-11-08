#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>

using namespace std::chrono;

minutes getDuration(const std::string& label) {

    int workMinutes;
    std::cout<<label;
    std::cin>>workMinutes;
    return minutes(workMinutes);
}


void countdown(minutes duration, const std::string& label) {

    int remainingTime = duration_cast<seconds>(duration).count();

    while(remainingTime >= 0){
        int minutesRemaining = remainingTime/60;
        int secondsRemaining = remainingTime%60;
        
        std::cout << "\r" << label << " " <<std::setfill('0') << std::setw(2) << minutesRemaining << ":" << 
        std::setfill('0') << std::setw(2)<< secondsRemaining << std::flush;
        std::this_thread::sleep_for(seconds(1));
        remainingTime--;
    }
}

void celebrate(const std::string& label) {
    std::cout << "\n\a" << label << " time is up! Celebrate!\n";
}

int main() {
    std::cout << "=== Pomodoro CLI ===\n";

    minutes work = getDuration("Work duration (minutes): ");
    minutes brk  = getDuration("Break duration (minutes): ");
    
    int cycles;
    std::cout << "Number of cycles: ";
    std::cin >> cycles;

    for(int i = 0; i < cycles; ++i) {
        countdown(work, "Work");
        celebrate("Work");
        countdown(brk, "Break");
        celebrate("Break");
    }

    return 0;
}
