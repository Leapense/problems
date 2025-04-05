cmake_minimum_required(VERSION 3.10)
project(GiftBoxTest)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gift_box_test ../test_gift_box.cpp)
target_link_libraries(gift_box_test ${GTEST_LIBRARIES} pthread)
