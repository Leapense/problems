#include <gtest/gtest.h>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> getOperations(long long x, long long y);
static long long gcdll(long long a, long long b);

static long long apply(long long x, long long z)
{
    if (z > 0)
        return x + z;
    else
        return x - llabs(z);
}

static void verifySequence(long long x0, long long y)
{
    auto ops = getOperations(x0, y);
    ASSERT_LE(ops.size(), 2u) << "Used more than 2 moves";
    long long x = x0;

    for (auto z : ops)
    {
        ASSERT_GE(llabs(z), 1);
        ASSERT_LE(llabs(z), (long long)1e18);
        ASSERT_GE(gcdll(x, llabs(z)), 1) << "gcd(" << x << "," << llabs(z) << ") == 1, invalid move";
        x = apply(x, z);
        ASSERT_GE(x, 1);
        ASSERT_LE(x, (long long)1e18);
    }

    ASSERT_EQ(x, y) << "Final x = " << x << ", expected y = " << y;
}

TEST(SampleTests, EqualCase)
{
    verifySequence(4, 4);
}

TEST(SampleTests, OneMoveCase)
{
    verifySequence(6, 9);
}

TEST(SampleTests, TwoMoveCase)
{
    verifySequence(7, 12);
}

TEST(Randomized, SomeRandomPairs)
{
    vector<pair<long long, long long>> pts = {
        {3, 5}, {10, 17}, {14, 15}, {1000000000, 2}, {999999937, 999999938}};
    for (auto [x, y] : pts)
    {
        verifySequence(x, y);
    }
}

static long long gcdll(long long a, long long b)
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}