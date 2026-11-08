cmake_minimum_required(VERSION 3.15)
project(pomoCLI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pomo
    src/main.cpp
    src/Timer.cpp
    src/Session.cpp
)

target_include_directories(pomo PRIVATE include)
