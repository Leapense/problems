#include <gtest/gtest.h>
#include "../cpp/src/main.h"

TEST(ForestTest, SampleTest)
{
    EXPECT_EQ(solve(2, 4, 3, 3, 25), 7);
}

TEST(ForestTest, SimpleTest)
{
    EXPECT_EQ(solve(1, 2, 1, 2, 2), 1);
}

TEST(ForestTest, RestTest)
{
    EXPECT_EQ(solve(3, 2, 3, 3, 10), 3);
}

TEST(ForestTest, BothRestDayTest)
{
    EXPECT_EQ(solve(2, 2, 3, 2, 10), 3);
}

TEST(ForestTest, LargeTest)
{
    EXPECT_EQ(solve(1000000000, 1000000000000000000LL, 1000000000, 1000000000000000000LL, 1000000000000000000LL), 500000000);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}