#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <cmath>

TEST(RaceTest, SampleTest)
{
    double v = 4, x = 10, y = 12, a = 1, b = 2;
    double expected = 8.5;
    double result = compute_min_time(v, x, y, a, b);
    EXPECT_NEAR(result, expected, 1e-8);
}

TEST(RaceTest, DecelerationLimitedTest)
{
    double v = 10, x = 5, y = 20, a = 1, b = 2;
    double t1 = sqrt(2 * x / b);
    double t2 = sqrt(2 * y / a);
    double expected = t1 + t2;
    double result = compute_min_time(v, x, y, a, b);
    EXPECT_NEAR(result, expected, 1e-8);
}

TEST(RaceTest, AccelerationLimitedTest)
{
    double v = 5, x = 50, y = 50, a = 2, b = 3;
    double t1 = (50 - (25.0 / 6)) / 5 + (5.0 / 3);
    double t2 = 2.5 + 8.75;
    double expected = t1 + t2;
    double result = compute_min_time(v, x, y, a, b);
    EXPECT_NEAR(result, expected, 1e-4);
}

TEST(RaceTest, EdgeCaseTest)
{
    double v = 1, x = 1, y = 1, a = 1, b = 1;
    double expected = 3.0;
    double result = compute_min_time(v, x, y, a, b);
    EXPECT_NEAR(result, expected, 1e-8);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}