#include <catch2/catch_test_macros.hpp>

#include "Timer.h"

TEST_CASE("formatTime handles boundary values", "[formatTime]") {
    SECTION("zero seconds") {
        REQUIRE(formatTime(0) == "00:00");
    }

    SECTION("under a minute") {
        REQUIRE(formatTime(5) == "00:05");
    }

    SECTION("exactly one minute") {
        REQUIRE(formatTime(60) == "01:00");
    }

    SECTION("seconds padding boundary (seconds < 10)") {
        REQUIRE(formatTime(61) == "01:01");
    }

    SECTION("minutes in double digits") {
        REQUIRE(formatTime(605) == "10:05");
    }
}
