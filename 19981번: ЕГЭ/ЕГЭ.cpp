#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

using namespace std;

vector<int> convertToNegativeBase2(long long x)
{
    vector<int> digits;

    if (x == 0)
    {
        digits.push_back(0);
        return digits;
    }

    while (x != 0)
    {
        long long r = x % -2;
        x /= -2;

        if (r < 0)
        {
            r += 2;
            x += 1;
        }

        digits.push_back(static_cast<int>(r));
    }

    return digits;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;

    vector<int> digits = convertToNegativeBase2(x);

    cout << digits.size() << "\n";

    for (size_t i = 0; i < digits.size(); i++)
    {
        cout << digits[i] << (i + 1 < digits.size() ? " " : "\n");
    }

    return 0;
}
#else

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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif