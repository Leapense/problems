// test_solution.cpp
#define UNIT_TEST
#include "solution.cpp"

#include <gtest/gtest.h>
#include <sstream>

// Sample from prompt:
TEST(PivotsSample, Sample1)
{
    istringstream in("10 1 11 8 13 53 20 63 99 79 94\n");
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), "3 1 13 63\n");
}

// Edge case: no valid pivot => output "0"
TEST(PivotsEdgeCase, NoPivot)
{
    istringstream in("5 5 4 3 2 1\n");
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), "0\n");
}

// Strictly increasing: every position is a pivot.
// We expect total = n, but only first 100 printed.
TEST(PivotsLarge, FirstHundred)
{
    const int N = 200;
    std::ostringstream seed;
    seed << N;
    for (int i = 1; i <= N; i++)
        seed << ' ' << i;
    seed << '\n';

    istringstream in(seed.str());
    ostringstream out;
    solve(in, out);

    // Build expected:
    std::ostringstream exp;
    exp << N;
    for (int i = 1; i <= 100; i++)
        exp << ' ' << i;
    exp << '\n';

    EXPECT_EQ(out.str(), exp.str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
