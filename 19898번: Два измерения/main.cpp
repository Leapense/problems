#include <iostream>
using namespace std;

long long countWays(long long l, long long r, long long a)
{
    long long T = r - l + 1;
    long long n = (r - l) / a;
    long long result = n * T - a * (n * (n + 1) / 2);
    return result;
}

#ifndef UNIT_TEST
int main()
{
    long long l, r, a;
    cin >> l >> r >> a;
    cout << countWays(l, r, a) << "\n";
    return 0;
}
#endif

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(MeasurementTests, Sample1)
{
    long long l = 1, r = 5, a = 2;
    EXPECT_EQ(countWays(l, r, a), 4);
}

TEST(MeasurementTests, Sample2)
{
    long long l = 4, r = 9, a = 6;
    EXPECT_EQ(countWays(l, r, a), 0);
}

TEST(MeasurementTests, MinimalCase)
{
    long long l = 1, r = 2, a = 1;
    EXPECT_EQ(countWays(l, r, a), 1);
}

TEST(MeasurementTests, NoValidPairs)
{
    long long l = 10, r = 20, a = 15;
    EXPECT_EQ(countWays(l, r, a), 0);
}

TEST(MeasurementTests, GeneralCase)
{
    long long l = 2, r = 20, a = 3;
    EXPECT_EQ(countWays(l, r, a), 51);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif