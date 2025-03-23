cmake_minimum_required(VERSION 3.10)
project(POWER_OF_TWO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
enable_testing()

add_executable(power_of_two
    cpp/src/main.cpp
)

add_executable(power_of_two_test
    test/Testmain.cpp
    cpp/src/main.cpp
)

target_compile_definitions(power_of_two_test PRIVATE UNIT_TESTS)
target_link_libraries(power_of_two_test PRIVATE GTest::gtest_main)
