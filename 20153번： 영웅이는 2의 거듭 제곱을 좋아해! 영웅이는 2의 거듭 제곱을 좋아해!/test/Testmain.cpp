#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../cpp/src/main.h"

TEST(SolveCaseTest, Sample1)
{
    std::vector<int> A = {5, 7, 11};
    std::string expected = "1414";
    EXPECT_EQ(solve(A), expected);
}

TEST(SolveCaseTest, Sample2)
{
    std::vector<int> A = {1, 2, 4};
    std::string expected = "77";
    EXPECT_EQ(solve(A), expected);
}

TEST(SolveCaseTest, SingleElement)
{
    std::vector<int> A = {10};
    std::string expected = "1010";
    EXPECT_EQ(solve(A), expected);
}

TEST(SolveCaseTest, DuplicateElements)
{
    std::vector<int> A = {2, 2};
    std::string expected = "22";
    EXPECT_EQ(solve(A), expected);
}

TEST(SolveCaseTest, MultipleElements)
{
    std::vector<int> A = {2, 4, 8, 16};
    std::string expected = "3030";
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}