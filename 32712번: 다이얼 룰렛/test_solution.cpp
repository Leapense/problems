// ----------  test_solution.cpp  ----------
#define UNIT_TEST       // tells solution.cpp not to emit main
#include "solution.cpp" // brings solve() into this TU

#include <gtest/gtest.h>
#include <sstream>
#include <string>

static std::string run(const std::string &input)
{
    std::istringstream in(input);
    std::ostringstream out;
    solve(in, out); // call the real algorithm
    return out.str();
}

/* --------------- samples ---------------- */
TEST(Samples, Case1)
{
    EXPECT_EQ(run("5 4\n1 4 2 1 2\n"), "13\n");
}
TEST(Samples, Case2)
{
    std::string in = "5 10\n"
                     "999999991 999999959 999999985 999999960 999999957\n";
    EXPECT_EQ(run(in), "9999999910\n");
}