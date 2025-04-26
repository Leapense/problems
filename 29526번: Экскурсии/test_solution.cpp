#include "solver.h"
#include <gtest/gtest.h>

TEST(Holiday, Sample)
{
    std::vector<long long> a = {1, 2, 1, 3, 1, 2, 1};
    EXPECT_EQ(bestHoliday(a, 3), 2);
}

TEST(Holiday, AllSame)
{
    std::vector<long long> a(100, 42);
    EXPECT_EQ(bestHoliday(a, 50), 1);
}

TEST(Holiday, AllDifferent)
{
    std::vector<long long> a;
    for (int i = 1; i <= 1000; ++i)
        a.push_back(i);
    EXPECT_EQ(bestHoliday(a, 1000), 1);
}