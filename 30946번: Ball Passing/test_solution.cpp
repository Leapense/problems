#define UNIT_TEST
#include "gtest/gtest.h"
#include <sstream>
#include <string>

// forward declaration from solution.cpp
void solve(std::istream &, std::ostream &);

static double run(const std::string &in)
{
    std::istringstream iss(in);
    std::ostringstream oss;
    solve(iss, oss);
    return std::stod(oss.str());
}

TEST(BallPassing, Sample1)
{
    const char *in =
        "4\n"
        "BGBG\n"
        "0 0\n0 1\n1 1\n1 0\n";
    EXPECT_NEAR(run(in), 2.828427125, 1e-6);
}

TEST(BallPassing, Sample2)
{
    const char *in =
        "4\n"
        "GGBB\n"
        "0 0\n0 1\n1 1\n1 0\n";
    EXPECT_NEAR(run(in), 2.0, 1e-6);
}

TEST(BallPassing, Sample3)
{
    const char *in =
        "12\n"
        "GBGBBGBBBBGB\n"
        "0 -15\n6 -14\n19 -5\n17 7\n11 12\n1 15\n"
        "-9 13\n-15 10\n-17 8\n-19 4\n-16 -9\n-13 -11\n";
    EXPECT_NEAR(run(in), 186.529031603, 1e-6);
}

// Extra sanity check: all students same gender (N=2)
TEST(BallPassing, Trivial2)
{
    const char *in =
        "2\n"
        "BB\n"
        "0 0\n3 4\n"; // distance = 5
    EXPECT_NEAR(run(in), 5.0, 1e-9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
