#include "../cpp/src/main.h"
#include <gtest/gtest.h>

TEST(GratitudeTest, SampleTest1)
{
    std::string input = R"(2 2
Supportive parents
Being able to solve a hard problem
Good food
Fun game with friends
Good food
Being healthy
)";
    std::string expected = R"(Good food
Being healthy)";
    EXPECT_EQ(solve(input), expected);
}

TEST(GratitudeTest, SampleTest2)
{
    std::string input = R"(2 6
Supportive parents
Being able to solve a hard problem
Good food
Fun game with friends
Good food
Being healthy
)";
    std::string expected = R"(Good food
Being healthy
Fun game with friends
Being able to solve a hard problem
Supportive parents)";
    EXPECT_EQ(solve(input), expected);
}

TEST(GratitudeTest, SingleDayOneOutput)
{
    std::string input = R"(1 1
A
B
C
)";
    // 각 항목의 빈도는 동일하므로 가장 최근 항목 "C"가 선택됨.
    std::string expected = "C";
    EXPECT_EQ(solve(input), expected);
}

TEST(GratitudeTest, SingleDayAllOutputs)
{
    std::string input = R"(1 3
A
B
C
)";
    // 빈도가 동일하므로 "C", "B", "A" 순서
    std::string expected = R"(C
B
A)";
    EXPECT_EQ(solve(input), expected);
}

TEST(GratitudeTest, MultipleDaysTieBreaker)
{
    std::string input = R"(3 2
X
Y
Z
X
Z
Y
Z
X
Y
)";
    // X: 빈도 3, 마지막 인덱스 7
    // Y: 빈도 3, 마지막 인덱스 8
    // Z: 빈도 3, 마지막 인덱스 6
    // 빈도가 동일하므로 최근 항목 우선 -> Y, X, Z
    std::string expected = R"(Y
X)";
    EXPECT_EQ(solve(input), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}