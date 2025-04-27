#include <gtest/gtest.h>
#include <sstream>
#include "solution.cpp"

static std::string run_case(const std::string &input)
{
    std::istringstream in(input);
    std::ostringstream out;
    solve(in, out);
    return out.str();
}

TEST(Sample, Case1)
{
    std::string input = "5 2 3\n4 6\n7 2\n5 5\n3 6\n10 9\n";
    EXPECT_EQ(run_case(input), "23\n");
}

TEST(Sample, Case2)
{
    std::string input = "2 1 1\n2 1\n3 4\n";
    EXPECT_EQ(run_case(input), "4\n");
}

TEST(Edge, AllFirstCheaper)
{
    std::string input = "3 2 1\n1 10\n1 10\n1 10\n";
    EXPECT_EQ(run_case(input), "12\n");
}

TEST(Edge, LargeEqualPrices)
{
    std::ostringstream inp;
    int N = 100000, A = 50000;
    inp << N << " " << A << " " << N - A << "\n";
    for (int i = 0; i < N; i++)
        inp << "1000000000 1000000000\n";
    EXPECT_EQ(run_case(inp.str()), std::to_string(1LL * N * 1000000000) + "\n");
}