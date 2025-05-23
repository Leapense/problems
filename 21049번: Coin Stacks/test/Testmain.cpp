#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(CoinStacksTest, SampleTest1)
{
    vector<int> coins = {1, 4, 3};
    auto res = solveCoinStacks(coins);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second.size(), 4);
}

TEST(CoinStacksTest, SampleTest2)
{
    vector<int> coins = {1, 1, 1};
    auto res = solveCoinStacks(coins);
    EXPECT_FALSE(res.first);
}

TEST(CoinStacksTest, AllZeroTest)
{
    vector<int> coins = {0, 0, 0, 0};
    auto res = solveCoinStacks(coins);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second.size(), 0);
}

TEST(CoinStacksTest, BalancedTest)
{
    vector<int> coins = {3, 3, 3, 3};
    auto res = solveCoinStacks(coins);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second.size(), 6);
}

TEST(CoinStacksTest, ImbalancedTest)
{
    vector<int> coins = {5, 1, 1};
    auto res = solveCoinStacks(coins);
    EXPECT_FALSE(res.first);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}