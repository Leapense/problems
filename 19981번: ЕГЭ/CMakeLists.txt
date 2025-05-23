cmake_minimum_required(VERSION 3.10)
project(NEGATIVE_BASE2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
enable_testing()

# 1) 실행 파일(메인 함수 포함)
add_executable(negative_base2
    cpp/src/main.cpp
)
# 여기서는 main.cpp가 그대로 컴파일됨 → 메인 함수 존재

# 2) 테스트 실행 파일
add_executable(negative_base2_test
    test/Testmain.cpp
    cpp/src/main.cpp
)
# 테스트 빌드에서는 메인 함수를 제외하도록 매크로 정의
target_compile_definitions(negative_base2_test PRIVATE UNIT_TESTS)
target_link_libraries(negative_base2_test PRIVATE GTest::gtest_main)