cmake_minimum_required(VERSION 4.1.2)
project(Dream_Steam_A_team_DSA_Project_2_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dream_Steam_A_team_DSA_Project_2_
        datasets.cpp
        main.cpp
        mergesort.cpp
        quicksort.cpp
        userinterface.cpp
        userinterface.h
        datasets.h
        mergesort.h)

add_compile_definitions(DATA_DIR="${CMAKE_SOURCE_DIR}/datafiles/")

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

