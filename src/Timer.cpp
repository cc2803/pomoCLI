#include "Timer.h"

#include <iostream>
#include <thread>

namespace {
// ANSI escape codes. Needs a VT100-capable terminal (Windows Terminal, or
// legacy cmd/PowerShell with ENABLE_VIRTUAL_TERMINAL_PROCESSING) — on an
// unsupported terminal these will render as garbage characters instead of
// color. No capability detection here; this is a known, documented limit.
const std::string kDigitsColor = "\033[1;37m"; // bold white
const std::string kColorReset = "\033[0m";

constexpr int kProgressBarWidth = 20;

std::string progressBar(int elapsedSeconds, int totalSeconds) {
    if (totalSeconds <= 0) {
        return "[" + std::string(kProgressBarWidth, '-') + "]";
    }

    int filled = elapsedSeconds * kProgressBarWidth / totalSeconds;
    std::string bar;
    for (int i = 0; i < kProgressBarWidth; ++i) {
        bar += (i < filled) ? "\xE2\x96\x88" : "-";
    }
    return "[" + bar + "]";
}
}

std::string formatTime(int totalSeconds) {

    std::string formattedTime;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    formattedTime = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

    return formattedTime;

}

Timer::Timer(std::chrono::seconds duration, std::function<void(std::chrono::seconds)> sleepCallback)
    : duration_(duration), sleepCallback_(sleepCallback) {}

void Timer::run(const std::string& label) {
    int totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(duration_).count();
    int remainingTime = totalSeconds;

    while (remainingTime >= 0) {
        int elapsed = totalSeconds - remainingTime;
        std::cout << "\r" << label << " " << kDigitsColor << formatTime(remainingTime) << kColorReset << progressBar(elapsed, totalSeconds) << std::flush;
        sleepCallback_(std::chrono::seconds(1));
        remainingTime--;
    }
}
