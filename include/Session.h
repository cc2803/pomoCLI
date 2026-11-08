#pragma once

#include <chrono>
#include <string>

void celebrate(const std::string& label);

class Session {
public:
    Session(std::chrono::minutes work, std::chrono::minutes brk, int cycles);

    void run();

private:
    std::chrono::minutes work_;
    std::chrono::minutes break_;
    int cycles_;
};
