#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

bool canReach(const vector<string> &grid)
{
    int n = grid.size();
    if (n == 0)
        return false;
    vector<bool> dp(n, false), next_dp(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                if (i == 0 && j == 0)
                {
                    next_dp[j] = true;
                }
                else
                {
                    bool from_up = (i > 0 && dp[j]);
                    bool from_left = (j > 0 && next_dp[j - 1]);
                    next_dp[j] = (from_up || from_left);
                }
            }
            else
            {
                next_dp[j] = false;
            }
        }

        dp = next_dp;
    }

    return dp[n - 1];
}

TEST(TractorPathTest, Sample1)
{
    vector<string> grid = {
        "..x...",
        ".x....",
        "....x.",
        "xx.x..",
        "..x...",
        "......"};
    EXPECT_FALSE(canReach(grid));
}

TEST(TractorPathTest, Sample2)
{
    vector<string> grid = {
        ".x.x.",
        ".....",
        "xxx..",
        "....x",
        ".x..."};
    EXPECT_TRUE(canReach(grid));
}

TEST(TractorPathTest, SingleCellOpen)
{
    vector<string> grid = {"."};
    EXPECT_TRUE(canReach(grid));
}

TEST(TractorPathTest, SingleCellBlocked)
{
    vector<string> grid = {"x"};
    EXPECT_FALSE(canReach(grid));
}

TEST(TractorPathTest, StartBlocked)
{
    vector<string> grid = {
        "x.",
        ".."};
    EXPECT_FALSE(canReach(grid));
}

TEST(TractorPathTest, EndBlocked)
{
    vector<string> grid = {
        "..",
        ".x"};
    EXPECT_FALSE(canReach(grid));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}