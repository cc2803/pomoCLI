#pragma once

#include <chrono>
#include <string>
#include <functional>
#include <thread>

std::string formatTime(int totalSeconds);

class Timer {
public:

    Timer(std::chrono::seconds duration, std::function<void(std::chrono::seconds)> sleepCallback = [](std::chrono::seconds s) { std::this_thread::sleep_for(s); });

    void run(const std::string& label);

private:
    std::chrono::seconds duration_;
    std::function<void(std::chrono::seconds)> sleepCallback_;
};
