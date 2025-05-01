#include "solution.cpp"
#include <gtest/gtest.h>

TEST(StarTrap, Sample1)
{
    int N = 4, M = 4;

    vector<vector<int>> A = {
        {1, 2, 2, 3},
        {2, 2, 1, 1},
        {3, 2, 1, 2},
        {1, 2, 2, 2}};
    auto ans = find_trapped(N, M, A);
    vector<int> expect = {2};
    EXPECT_EQ(ans, expect);
}

TEST(StarTrap, Sample2)
{
    int N = 6, M = 5;
    vector<vector<int>> A = {
        {3, 1, 1, 2, 1},
        {4, 2, 1, 3, 1},
        {4, 1, 1, 3, 3},
        {4, 3, 3, 1, 2},
        {5, 1, 1, 2, 2},
        {3, 2, 3, 3, 3}};

    auto ans = find_trapped(N, M, A);
    vector<int> expect = {2, 3, 4};
    EXPECT_EQ(ans, expect);
}

TEST(StarTrap, Sample3)
{
    int N = 5, M = 6;
    vector<vector<int>> A = {
        {5, 2, 3, 3, 1, 1},
        {4, 2, 2, 1, 1, 3},
        {3, 1, 2, 2, 1, 3},
        {5, 3, 2, 1, 1, 2},
        {3, 2, 3, 3, 3, 2}};

    auto ans = find_trapped(N, M, A);
    EXPECT_TRUE(ans.empty());
}

TEST(StarTrap, SingleCell)
{
    int N = 1, M = 1;
    vector<vector<int>> A = {{1}};

    auto ans = find_trapped(N, M, A);
    EXPECT_TRUE(ans.empty());
}

TEST(StarTrap, OneRowCycle)
{
    int N = 1, M = 3;
    vector<vector<int>> A = {{2, 1, 1}};
    auto ans = find_trapped(N, M, A);
    EXPECT_TRUE(ans.empty());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}