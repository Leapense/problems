cmake_minimum_required(VERSION 3.10)
project(GAME_ADDICTION LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
enable_testing()

add_executable(Chess
    cpp/src/main.cpp
)

add_executable(Chess_test
    test/Testmain.cpp
    cpp/src/main.cpp
)

target_compile_definitions(Chess_test PRIVATE UNIT_TESTS)
target_link_libraries(Chess_test PRIVATE GTest::gtest_main)
