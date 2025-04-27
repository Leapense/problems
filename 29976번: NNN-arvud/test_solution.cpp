#include <gtest/gtest.h>
#include <vector>
#include <string>
std::vector<std::string> solve(int);

TEST(NNN, SampleInput1)
{
    std::vector<std::string> expect = {"20021"};
    EXPECT_EQ(solve(5), expect);
}

TEST(NNN, SampleInput2)
{
    EXPECT_TRUE(solve(2).empty());
}