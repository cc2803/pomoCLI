#include <catch2/catch_test_macros.hpp>

#include "Timer.h"

TEST_CASE("Timer calls its sleep callback once per tick, without real sleeping", "[Timer]") {
    int callCount = 0;
    auto countingCallback = [&callCount](std::chrono::seconds) {
        callCount++;
    };

    Timer timer(std::chrono::seconds(3), countingCallback);
    timer.run("Test");

    REQUIRE(callCount == 4); // The callback should be called 4 times for a 3-second duration (3, 2, 1, 0).
}
