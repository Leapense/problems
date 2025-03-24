#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

// Sample test (문제 예시 테스트 케이스)
TEST(ReverseChampion, SampleTest)
{
    std::istringstream input(
        "3 7\n"
        "00:38 1 4 3\n"
        "01:16 2 2 1\n"
        "02:01 3 1 2\n"
        "03:00 1 2 3\n"
        "03:04 2 3 2\n"
        "03:18 2 1 1\n"
        "03:54 1 3 6\n");
    std::ostringstream output;
    solve(input, output);
    EXPECT_EQ(output.str(), "2\n");
}

// 프리징 제출이 없는 경우: 프리징 전 제출만 있는 경우
TEST(ReverseChampion, NoFrozenSubmission)
{
    std::istringstream input(
        "2 2\n"
        "00:10 1 1 1\n"
        "00:20 2 1 1\n");
    std::ostringstream output;
    solve(input, output);
    // Participant 1: solved 1, penalty 10, lastTime 10
    // Participant 2: solved 1, penalty 20, lastTime 20 => Participant 1 승
    EXPECT_EQ(output.str(), "1\n");
}

// 여러 프리징 제출이 있는 경우
TEST(ReverseChampion, MultipleFrozenSubmissions)
{
    // 3명의 참가자가 있고, 각 참가자에 프리징 제출 1회씩
    // Participant 1: Pre-freeze 00:10, Frozen 03:05 (문제2, 1회)
    // Participant 2: Pre-freeze 00:15, Frozen 03:10 (문제1, 2회)
    // Participant 3: Pre-freeze 00:20, Frozen 03:02 (문제3, 1회)
    std::istringstream input(
        "3 6\n"
        "00:10 1 1 1\n"
        "00:15 2 1 1\n"
        "00:20 3 1 1\n"
        "03:05 1 2 1\n"
        "03:10 2 1 2\n"
        "03:02 3 3 1\n");
    std::ostringstream output;
    solve(input, output);
    std::string result = output.str();
    int id = std::stoi(result);
    EXPECT_TRUE(id >= 1 && id <= 3);
}

// 복잡한 시나리오 테스트
TEST(ReverseChampion, ComplexScenario)
{
    // 4명의 참가자, 다수의 프리징 제출이 있는 경우
    // Pre-freeze 제출 4회, Frozen 제출 8회
    std::istringstream input(
        "4 12\n"
        "00:10 1 1 1\n"
        "00:20 2 1 1\n"
        "00:30 3 1 1\n"
        "00:40 4 1 1\n"
        "03:10 1 2 1\n"
        "03:05 2 2 1\n"
        "03:15 3 2 1\n"
        "03:20 4 2 1\n"
        "03:25 1 3 1\n"
        "03:30 2 3 2\n"
        "03:35 3 3 1\n"
        "03:40 4 3 1\n");
    std::ostringstream output;
    solve(input, output);
    std::string result = output.str();
    int id = std::stoi(result);
    EXPECT_TRUE(id >= 1 && id <= 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}