#include <gtest/gtest.h>
#include "../cpp/src/main.h"

TEST(ComputeMaxTabsTest, SampleTest1)
{
    EXPECT_EQ(computeMaxTabs(23, 3), 10);
}

TEST(ComputeMaxTabsTest, SampleTest2)
{
    EXPECT_EQ(computeMaxTabs(2, 3), 2);
}

TEST(ComputeMaxTabsTest, SmallMemoryTest)
{
    EXPECT_EQ(computeMaxTabs(1, 1), 1);
}

TEST(ComputeMaxTabsTest, ModerateTest)
{
    EXPECT_EQ(computeMaxTabs(100, 5), 29);
}

TEST(ComputeMaxTabsTest, EdgeTest)
{
    long long result = computeMaxTabs(1000000000000000000LL, 1000000000LL);
    EXPECT_GE(result, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}