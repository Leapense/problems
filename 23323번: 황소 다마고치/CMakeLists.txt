cmake_minimum_required(VERSION 3.10)
project(GAME_ADDICTION LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
enable_testing()

add_executable(boj_23323
    Testmain.cpp
)

target_compile_definitions(boj_23323 PRIVATE UNIT_TESTS)
target_link_libraries(boj_23323 PRIVATE GTest::gtest_main)
