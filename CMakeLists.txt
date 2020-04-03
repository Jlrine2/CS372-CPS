cmake_minimum_required(VERSION 3.13)
project(CS372_CPS)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(tests)

add_executable(TEST
        src/cps.cpp
        src/cps.hpp
        tests/catch.hpp
        tests/cps_test_cases.cpp
        tests/cps_test_main.cpp)

add_executable(MAIN
        src/cps.cpp
        src/cps.hpp
        main.cpp)