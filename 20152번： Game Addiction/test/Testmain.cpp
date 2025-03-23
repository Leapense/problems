#include <gtest/gtest.h>
#include "../cpp/src/main.h"

using namespace std;

TEST(CountPathsTest, SameStartAndDestination)
{
    EXPECT_EQ(countPaths(5, 5), 1);
}

TEST(CountPathsTest, SampleTest1)
{
    EXPECT_EQ(countPaths(8, 4), 14);
}

TEST(CountPathsTest, SampleTest2)
{
    EXPECT_EQ(countPaths(0, 3), 5);
}

TEST(CountPathsTest, AdditionalTestIncreasing)
{
    EXPECT_EQ(countPaths(2, 5), 5);
}

TEST(CountPathsTest, AdditionalTestDecreasing)
{
    EXPECT_EQ(countPaths(5, 2), 5);
}

TEST(CountPathsTest, EdgeTestZeroCoordinates)
{
    EXPECT_EQ(countPaths(0, 0), 1);
}