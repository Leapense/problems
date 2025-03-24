#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <sstream>

// 최소 입력 n = "1": 첫 플레이어는 1 이상의 숫자를 선택할 수 있으므로 바로 승리.
TEST(GameTest, SingleDigitOne)
{
    std::string n = "1";
    EXPECT_EQ(solveGame(n), "First");
}

// 샘플 테스트 케이스: n = "22" -> "First"
TEST(GameTest, SampleTest22)
{
    std::string n = "22";
    EXPECT_EQ(solveGame(n), "First");
}

// n = "10": L = 2, 첫 플레이어의 선택이 제한되어 두 번째 플레이어가 승리
TEST(GameTest, Test10)
{
    std::string n = "10";
    EXPECT_EQ(solveGame(n), "Second");
}

// n = "100": L = 3, 분석 결과 첫 플레이어 승리
TEST(GameTest, Test100)
{
    std::string n = "100";
    EXPECT_EQ(solveGame(n), "First");
}

// n = "123": L = 3, 첫 플레이어가 유리한 전략으로 승리
TEST(GameTest, Test123)
{
    std::string n = "123";
    EXPECT_EQ(solveGame(n), "First");
}

// n = "99": L = 2, 첫 플레이어가 하강 편차 전략으로 승리
TEST(GameTest, Test99)
{
    std::string n = "99";
    EXPECT_EQ(solveGame(n), "First");
}

// n = "101": L = 3, 첫 플레이어 승리
TEST(GameTest, Test101)
{
    std::string n = "101";
    EXPECT_EQ(solveGame(n), "First");
}

// n = "98": L = 2, 첫 플레이어 승리
TEST(GameTest, Test98)
{
    std::string n = "98";
    EXPECT_EQ(solveGame(n), "First");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}