#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <sstream>
#include <string>

TEST(BSUTest, SampleTest)
{
    std::istringstream input("2 3 1\n0 0\n1 1 1\n2\n");
    std::ostringstream output;
    BSU::solve(input, output);
    EXPECT_EQ(output.str(), "1");
}

TEST(BSUTest, ZeroDifferenceTest)
{
    std::istringstream input("1 1 1\n0\n1\n1\n");
    std::ostringstream output;
    BSU::solve(input, output);
    EXPECT_EQ(output.str(), "0");
}

TEST(BSUTest, LargerCaseTest)
{
    std::istringstream input("3 5 1\n0 0 1\n0 1 1 1 0\n3\n");
    std::ostringstream output;
    BSU::solve(input, output);
    EXPECT_EQ(output.str(), "1");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}