#include <gtest/gtest.h>
#include <cmath>

long double compute_limit(long double b, long double c)
{
    long double disc = b * b + 4.0L * c;
    long double sqrt_disc = std::sqrt(disc);
    return (b + sqrt_disc) / 2.0L;
}

TEST(LimitTest, Fibonacci)
{
    EXPECT_NEAR((double)compute_limit(1, 1), 1.6180339887, 1e-6);
}

TEST(LimitTest, TwoThree)
{
    EXPECT_NEAR((double)compute_limit(2, 3), 3.0, 1e-6);
}

TEST(LimitTest, ThreeFour)
{
    EXPECT_NEAR((double)compute_limit(3, 4), 4.0, 1e-6);
}

TEST(LimitTest, FiveSix_IgnoringA1A2)
{
    EXPECT_NEAR((double)compute_limit(5, 6), 6.0, 1e-6);
}

TEST(LimitTest, TenOne)
{
    EXPECT_NEAR((double)compute_limit(10, 1), 10.099019513, 1e-6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
