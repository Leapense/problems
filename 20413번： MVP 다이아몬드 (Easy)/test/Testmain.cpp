#include "gtest/gtest.h"
#include "../cpp/src/main.h"

// Sample Test Case 1
TEST(SolveMVPTest, SampleTest1)
{
    int N = 3;
    int s = 30, g = 60, p = 90, d = 150;
    std::string grades = "BSG";
    int expected = 118;
    EXPECT_EQ(solveMVP(N, s, g, p, d, grades), expected);
}

// Sample Test Case 2
TEST(SolveMVPTest, SampleTest2)
{
    int N = 10;
    int s = 257, g = 269, p = 367, d = 500;
    std::string grades = "BSGGGGPPDD";
    int expected = 2499;
    EXPECT_EQ(solveMVP(N, s, g, p, d, grades), expected);
}

// Additional Test: Single Month Bronze
TEST(SolveMVPTest, SingleMonthBronze)
{
    int N = 1;
    int s = 30, g = 60, p = 90, d = 150;
    std::string grades = "B";
    // For Bronze in one month, maximum spending = s-1.
    int expected = 29;
    EXPECT_EQ(solveMVP(N, s, g, p, d, grades), expected);
}

// Additional Test: Single Month Diamond
TEST(SolveMVPTest, SingleMonthDiamond)
{
    int N = 1;
    int s = 30, g = 60, p = 90, d = 150;
    std::string grades = "D";
    // For Diamond in one month, spending must be exactly d.
    int expected = 150;
    EXPECT_EQ(solveMVP(N, s, g, p, d, grades), expected);
}

// Additional Test: Increasing Grades Pattern
TEST(SolveMVPTest, IncreasingGrades)
{
    int N = 5;
    int s = 10, g = 20, p = 30, d = 40;
    // Example grade sequence: B, S, G, P, D
    // This test ensures our DP handles various transitions.
    std::string grades = "BSGPD";
    int result = solveMVP(N, s, g, p, d, grades);
    // Since the maximum monthly spending is d, the maximum possible sum is 5 * d = 200.
    EXPECT_LE(result, 200);
    EXPECT_GE(result, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}