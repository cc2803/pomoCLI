#include "Timer.h"

#include <iostream>
#include <thread>

std::string formatTime(int totalSeconds) {

    std::string formattedTime;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    formattedTime = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

    return formattedTime;

}

Timer::Timer(std::chrono::seconds duration) : duration_(duration) {}

void Timer::run(const std::string& label) {
    int remainingTime = std::chrono::duration_cast<std::chrono::seconds>(duration_).count();

    while (remainingTime >= 0) {
        std::cout << "\r" << label << " " << formatTime(remainingTime) << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        remainingTime--;
    }
}
