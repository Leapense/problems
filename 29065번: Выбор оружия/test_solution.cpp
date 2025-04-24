#include <gtest/gtest.h>
#include <sstream>
#include <string>

extern std::string Solve(std::istream &);

TEST(WeaponChoice, Sample1)
{
    std::istringstream in("2 1\n1 2\n1 2\n");
    std::string expected = "3\n1 0\n";
    EXPECT_EQ(Solve(in), expected);
}

TEST(WeaponChoice, Sample2)
{
    std::istringstream in("3 1\n1 2\n1 3\n2 1\n");
    std::string expected = "7\n1 1 0\n";
    EXPECT_EQ(Solve(in), expected);
}
