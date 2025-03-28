#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool checkNoBingo(const vector<string> &grid)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        if (count(grid[i].begin(), grid[i].end(), '#') == n)
            return false;
    }

    for (int j = 0; j < n; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
                cnt++;
        }
        if (cnt == n)
            return false;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][i] == '#')
            cnt++;
    }

    if (cnt == n)
        return false;
    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (grid[i][n - 1 - i] == '#')
            cnt++;
    }

    if (cnt == n)
        return false;
    return true;
}

TEST(BingoTest, SingleCellValid)
{
    auto res = solveBingo(1, 0);
    EXPECT_TRUE(res.first);
    EXPECT_EQ(res.second.size(), 1);
    EXPECT_EQ(res.second[0], ".");
}

TEST(BingoTest, SingleCellInvalid)
{
    auto res = solveBingo(1, 1);
    EXPECT_FALSE(res.first);
}

TEST(BingoTest, TwoByTwoValid)
{
    auto res = solveBingo(2, 1);
    EXPECT_TRUE(res.first);
    int count = 0;
    for (auto &s : res.second)
    {
        count += count_if(s.begin(), s.end(), [](char c)
                          { return c == '#'; });
    }
    EXPECT_EQ(count, 1);
    EXPECT_TRUE(checkNoBingo(res.second));
}

TEST(BingoTest, TwoByTwoInvalid)
{
    auto res = solveBingo(2, 2);
    EXPECT_FALSE(res.first);
}

TEST(BingoTest, ThreeByThreeMaxValid)
{
    auto res = solveBingo(3, 6);
    EXPECT_TRUE(res.first);
    int count = 0;
    for (auto &s : res.second)
    {
        count += count_if(s.begin(), s.end(), [](char c)
                          { return c == '#'; });
    }
    EXPECT_EQ(count, 6);
    EXPECT_TRUE(checkNoBingo(res.second));
}

TEST(BingoTest, FourByFourInvalid)
{
    auto res = solveBingo(4, 16);
    EXPECT_FALSE(res.first);
}

TEST(BingoTest, FourByFourValid)
{
    auto res = solveBingo(4, 10);
    EXPECT_TRUE(res.first);
    int count = 0;
    for (auto &s : res.second)
    {
        count += count_if(s.begin(), s.end(), [](char c)
                          { return c == '#'; });
    }
    EXPECT_EQ(count, 10);
    EXPECT_TRUE(checkNoBingo(res.second));
}

TEST(BingoTest, LargerGridTest)
{
    auto res = solveBingo(5, 20);
    EXPECT_TRUE(res.first);
    int count = 0;
    for (auto &s : res.second)
    {
        count += count_if(s.begin(), s.end(), [](char c)
                          { return c == '#'; });
    }
    EXPECT_EQ(count, 20);
    EXPECT_TRUE(checkNoBingo(res.second));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}