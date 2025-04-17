#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

int minItems(const vector<int> &weights, int W)
{
    int x = weights.size();
    const int INF = x + 1;
    vector<int> dp(W + 1, INF);
    dp[0] = 0;
    for (int wt : weights)
    {
        if (wt > W)
            continue;
        for (int w = W; w >= wt; --w)
        {
            dp[w] = min(dp[w], dp[w - wt] + 1);
        }
    }

    return (dp[W] <= x ? dp[W] : -1);
}

TEST(BagsTest, Sample1)
{
    vector<int> weights = {1, 3, 3, 3, 5, 7, 7, 5, 5, 10};
    EXPECT_EQ(minItems(weights, 39), 6);
}

TEST(BagsTest, Sample2)
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(minItems(weights, 27), 3);
}

TEST(BagsTest, Sample3)
{
    vector<int> weights = {100};
    EXPECT_EQ(minItems(weights, 50), -1);
}

TEST(BagsTest, ZeroWeight)
{
    vector<int> weights = {5, 10, 15};
    EXPECT_EQ(minItems(weights, 0), 0);
}

TEST(BagsTest, SingleExactItem)
{
    vector<int> weights = {5, 10, 3};
    EXPECT_EQ(minItems(weights, 3), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}