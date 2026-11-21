cmake_minimum_required(VERSION 3.15)
project(pomoCLI VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(pomo_lib
    src/Timer.cpp
    src/Session.cpp
)
target_include_directories(pomo_lib PUBLIC include)

add_executable(pomo src/main.cpp)
target_link_libraries(pomo PRIVATE pomo_lib)

enable_testing()
add_subdirectory(tests)
