cmake_minimum_required(VERSION 4.1.2)

project(Dream_Steam_A_team_DSA_Project_2_)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Dream_Steam_A_team_DSA_Project_2_
        datasets.cpp
        main.cpp
        mergesort.cpp
        quicksort.cpp
        userinterface.cpp
        userinterface.h
        datasets.h
)

# GUI STUFF
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(Dream_Steam_A_team_DSA_Project_2_
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_compile_definitions(DATA_DIR="${CMAKE_SOURCE_DIR}/datafiles/")

# TESTCASES
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(unit_tests tests.cpp)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")

include(Catch)

catch_discover_tests(unit_tests)
