#include "gtest/gtest.h"
#include "../cpp/src/main.h"

using namespace std;

TEST(NegativeBase2, ZeroCase)
{
    long long x = 0;
    vector<int> expected = {0};
    EXPECT_EQ(convertToNegativeBase2(x), expected);
}

TEST(NegativeBase2, PositiveCase)
{
    long long x = 3;
    vector<int> expected = {1, 1, 1};
    EXPECT_EQ(convertToNegativeBase2(x), expected);
}

TEST(NegativeBase2, NegativeCase)
{
    long long x = -2;
    vector<int> expected = {0, 1};
    EXPECT_EQ(convertToNegativeBase2(x), expected);
}

TEST(NegativeBase2, LargerNumber)
{
    long long x = 10;
    vector<int> digits = convertToNegativeBase2(x);
    long long reconstructed = 0, base = 1;
    for (int d : digits)
    {
        reconstructed += d * base;
        base *= -2;
    }
    EXPECT_EQ(reconstructed, x);
}