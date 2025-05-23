#include <iostream>
#include <numeric>
#include <cassert>

using namespace std;

long long modInverse2(long long m)
{
    long long a = 2, b = m;
    long long x0 = 1, y0 = 0;
    long long x1 = 0, y1 = 1;

    while (b)
    {
        long long q = a / b;
        long long t = a % b;

        a = b;
        b = t;
        t = x0 - q * x1;
        x0 = x1;
        x1 = t;
        t = y0 - q * y1;
        y0 = y1;
        y1 = t;
    }

    x0 %= m;
    if (x0 < 0)
        x0 += m;
    return x0;
}

long long solveCase(long long a, long long b, long long c)
{
    long long d = b - a;
    if (d % 2 == 1)
    {
        return (d + 1) / 2;
    }

    long long n0 = d / 2;
    long long f = ((-a) % c + c) % c;
    bool forced = false;

    if (c % 2 == 1)
    {
        long long inv2 = modInverse2(c);
        long long i0 = (f * inv2) % c;
        if (i0 == 0)
            i0 = c;

        if (i0 <= n0 - 1)
        {
            forced = true;
        }
    }

    return forced ? n0 + 1 : n0;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;
    cout << solveCase(a, b, c) << "\n";
    return 0;
}
#endif

#ifdef UNIT_TEST
#include <gtest/gtest.h>

TEST(MarsohodTest, SampleTest1)
{
    EXPECT_EQ(solveCase(2, 7, 3), 3);
}

TEST(MarsohodTest, SampleTest2)
{
    EXPECT_EQ(solveCase(4, 10, 3), 4);
}

TEST(MarsohodTest, OddDifferenceCase)
{
    EXPECT_EQ(solveCase(5, 12, 7), 4);
}

TEST(MarsohodTest, EvenC_NoConflict)
{
    EXPECT_EQ(solveCase(3, 9, 4), 3);
}

TEST(MarsohodTest, EdgeCaseLargeValues)
{
    long long a = 100000000, b = 100000050, c = 13;
    long long ans = solveCase(a, b, c);
    EXPECT_GT(ans, 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif