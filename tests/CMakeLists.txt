include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(pomo_tests
    test_formatTime.cpp
    test_Timer.cpp
)
target_link_libraries(pomo_tests PRIVATE pomo_lib Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
include(CTest)
include(Catch)
catch_discover_tests(pomo_tests)

# Session::run() is intentionally not unit-tested: it's pure orchestration
# (looping, constructing Timers, calling celebrate()) with no independent
# branching logic worth isolating from the pieces it coordinates.
