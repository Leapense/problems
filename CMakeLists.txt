cmake_minimum_required(VERSION 3.10)
project(TestCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(GoogleTest)

add_subdirectory("19981번： ЕГЭ")
add_subdirectory("20006번： 랭킹전 대기열")

