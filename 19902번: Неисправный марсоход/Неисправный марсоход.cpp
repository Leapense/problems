#include <iostream>
#include <numeric>
using namespace std;

// Function to compute modular inverse of 2 modulo m (m is odd).
// Since m is odd, the inverse always exists.
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

// solveCase computes the minimal number of signals needed.
long long solveCase(long long a, long long b, long long c)
{
    long long d = b - a;
    // When the difference is odd, we can always order moves to avoid forbidden state.
    if (d % 2 == 1)
    {
        return (d + 1) / 2;
    }

    // d is even; if no forbidden prefix occurs using all Y (2-signal) moves,
    // then minimal moves would be n0 = d/2.
    long long n0 = d / 2;
    // The forbidden condition is that battery power becomes divisible by c.
    // Let S be the prefix sum. We require (a + S) % c != 0.
    // That is equivalent to S ≢ (-a) mod c.
    long long f = ((-a) % c + c) % c; // f is in [0, c-1]
    // Note: since a is not divisible by c, f ≠ 0.

    bool forced = false; // indicates whether the forced (all Y) sequence hits a forbidden prefix.
    if (c % 2 == 1)
    {
        // For odd c, gcd(2, c) == 1 so we solve: 2*i ≡ f (mod c)
        long long inv2 = modInverse2(c);
        long long i0 = (f * inv2) % c;
        if (i0 == 0)
            i0 = c; // smallest positive solution in 1..c
        if (i0 <= n0 - 1)
        {
            forced = true;
        }
    }
    else
    {
        // For even c, note that gcd(2, c) = 2.
        // The congruence 2*i ≡ f (mod c) has a solution if and only if f is even.
        if (f % 2 == 0)
        {
            long long fprime = f / 2;
            long long cprime = c / 2;
            // Now solve i ≡ fprime (mod cprime).
            long long i0 = fprime % cprime;
            if (i0 == 0)
                i0 = cprime; // smallest positive solution in 1..cprime
            if (i0 <= n0 - 1)
            {
                forced = true;
            }
        }
        // If f is odd, then 2*i (always even) cannot be congruent to f.
    }

    // If the forced (all Y) sequence has a forbidden prefix,
    // then one extra signal is needed.
    return forced ? n0 + 1 : n0;
}

#ifndef UNIT_TEST
// Main function for normal execution: reads input and prints output.
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
// Google Test unit tests
#include <gtest/gtest.h>

TEST(MarsohodTest, SampleTest1)
{
    // Sample Input 1: a=2, b=7, c=3 -> d=5 (odd), expected answer = 3.
    EXPECT_EQ(solveCase(2, 7, 3), 3);
}

TEST(MarsohodTest, SampleTest2)
{
    // Sample Input 2: a=4, b=10, c=3 -> d=6 (even) and forced prefix exists, expected answer = 4.
    EXPECT_EQ(solveCase(4, 10, 3), 4);
}

TEST(MarsohodTest, OddDifferenceCase)
{
    // When d is odd the answer is (d+1)/2.
    // Example: a=5, b=12, c=7 (d=7), expected answer = 4.
    EXPECT_EQ(solveCase(5, 12, 7), 4);
}

TEST(MarsohodTest, EvenC_NoConflict)
{
    // For even c, if a mod c is odd then f is odd and no solution for 2*i ≡ f exists.
    // Example: a=3, b=9, c=4 -> d=6, expected answer = 3.
    EXPECT_EQ(solveCase(3, 9, 4), 3);
}

TEST(MarsohodTest, EvenC_WithConflict)
{
    // For even c where a is even, f becomes even so a conflict may occur.
    // Example: a=2, b=10, c=4 -> d=8, forced prefix exists so expected answer = 5.
    EXPECT_EQ(solveCase(2, 10, 4), 5);
}

TEST(MarsohodTest, AnotherEvenC_WithConflict)
{
    // Example: a=6, b=12, c=4 -> d=6.
    // The forced sequence (all Y: 6->8->10->12) fails because 6+2=8 is divisible by 4.
    // Expected answer = 4.
    EXPECT_EQ(solveCase(6, 12, 4), 4);
}

TEST(MarsohodTest, EvenC_OddF_NoConflict)
{
    // For even c with a mod c odd, no conflict arises.
    // Example: a=5, b=9, c=6 -> d=4.
    // Here, a mod 6 = 5 so f = (-5 mod6) = 1 (odd), thus no conflict.
    // Expected answer = d/2 = 2.
    EXPECT_EQ(solveCase(5, 9, 6), 2);
}

TEST(MarsohodTest, EdgeCaseLargeValues)
{
    // Large values to ensure performance: a=100000000, b=100000050, c=13.
    // d = 50, even; we check that the result is computed quickly and is positive.
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
