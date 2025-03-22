cmake_minimum_required(VERSION 3.10)
project(EGE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(googletest-1.16.0)

add_library(SrcLib STATIC
    cpp/src/main.cpp
    cpp/src/main.h
)

add_executable(EGE_Test
    test/Testmain.cpp
)

target_link_libraries(EGE_Test PRIVATE
    gtest_main
    SrcLib
)

include(GoogleTest)
gtest_discover_tests(EGE_Test)