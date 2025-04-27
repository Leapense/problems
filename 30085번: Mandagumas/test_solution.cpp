#include <gtest/gtest.h>
#include "solution.cpp"

TEST(MandagumasTest, Sample1)
{
    int N = 5;
    vector<char> ops = {'A', 'A', 'B', 'A'};
    vector<int> expected = {1, 5, 4, 3, 2};
    EXPECT_EQ(solve(N, ops), expected);
}

TEST(MandagumasTest, NoDoors)
{
    int N = 3;
    vector<char> ops = {};
    vector<int> expected = {1, 2, 3};
    EXPECT_EQ(solve(N, ops), expected);
}

TEST(MandagumasTest, AllA)
{
    int N = 4;
    vector<char> ops = {'A', 'A', 'A', 'A'};
    vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(solve(N, ops), expected);
}

TEST(MandagumasTest, AllB)
{
    int N = 4;
    vector<char> ops = {'B', 'B', 'B'};
    vector<int> expected = {4, 3, 2, 1};
    EXPECT_EQ(solve(N, ops), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}