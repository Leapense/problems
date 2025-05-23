#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <string>
using namespace std;

TEST(NecklaceTest, SampleTest)
{
    string input = "4\n3 2 4 1\n";
    string output = solveNecklaceProblem(input);
    EXPECT_TRUE(validateSolution(input, output));
}

TEST(NecklaceTest, AlreadySorted)
{
    string input = "3\n1 2 3\n";
    string output = solveNecklaceProblem(input);
    EXPECT_TRUE(validateSolution(input, output));
}

TEST(NecklaceTest, TwoRingUnsolvable)
{
    string input = "2\n2 1\n";
    string output = solveNecklaceProblem(input);
    EXPECT_EQ(output, "-1\n");
    EXPECT_TRUE(validateSolution(input, output));
}

TEST(NecklaceTest, FiveRingTest)
{
    string input = "5\n3 1 4 2 5\n";
    string output = solveNecklaceProblem(input);
    EXPECT_TRUE(validateSolution(input, output));
}

TEST(NecklaceTest, SixRingTest)
{
    string input = "6\n4 6 1 3 2 5\n";
    string output = solveNecklaceProblem(input);
    EXPECT_TRUE(validateSolution(input, output));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}