#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(SolveDiplomasTest, SampleTest)
{
    EXPECT_EQ(solveDiplomas(2, 3, 10), 9);
}

TEST(SolveDiplomasTest, MinimalTest)
{
    EXPECT_EQ(solveDiplomas(1, 1, 1), 1);
}

TEST(SolveDiplomasTest, TwoDiplomaTest)
{
    EXPECT_EQ(solveDiplomas(1, 1, 2), 2);
}

TEST(SolveDiplomasTest, SingleDiplomaTest)
{
    EXPECT_EQ(solveDiplomas(3, 3, 1), 3);
}

TEST(SolveDiplomasTest, DifferentDimensionsTest)
{
    EXPECT_EQ(solveDiplomas(3, 2, 5), 6);
}

TEST(SolveDiplomasTest, SquareDiplomasTest)
{
    EXPECT_EQ(solveDiplomas(2, 2, 4), 4);
}

TEST(SolveDiplomasTest, LargeInputTest)
{
    EXPECT_EQ(solveDiplomas(1000000000LL, 1000000000LL, 4), 2000000000LL);
}

TEST(SolveDiplomasTest, VeryLargeTest)
{
    EXPECT_EQ(solveDiplomas(1000000000LL, 1000000000LL, 1000000000LL), 31623000000000LL);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}