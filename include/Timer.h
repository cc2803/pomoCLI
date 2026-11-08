#pragma once

#include <chrono>
#include <string>

std::string formatTime(int totalSeconds);

class Timer {
public:
    explicit Timer(std::chrono::seconds duration);

    void run(const std::string& label);

private:
    std::chrono::seconds duration_;
};
