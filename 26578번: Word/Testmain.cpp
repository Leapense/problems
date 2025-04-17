#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

long long countWordInstances(const vector<string> &grid)
{
    static const string target = "word";
    static constexpr int L = 4;
    static constexpr int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    static constexpr int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int r = grid.size();
    int c = r ? grid[0].size() : 0;
    long long count = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int x = i, y = j, k;
                for (k = 0; k < L; k++)
                {
                    if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != target[k])
                    {
                        break;
                    }
                    x += dx[dir];
                    y += dy[dir];
                }
                if (k == L)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

TEST(WordSearchTest, SampleInput1)
{
    vector<string> grid = {
        "word",
        "aoah",
        "nerd",
        "qpid"};

    EXPECT_EQ(countWordInstances(grid), 2);
}

TEST(WordSearchTest, SampleInput2)
{
    vector<string> grid = {
        "sowk",
        "dyuf",
        "asaf",
        "diub"};

    EXPECT_EQ(countWordInstances(grid), 0);
}

TEST(WordSearchTest, HorizontalBackward)
{
    vector<string> grid = {
        "drow"};

    EXPECT_EQ(countWordInstances(grid), 1);
}

TEST(WordSearchTest, VerticalForwardAndBackward)
{
    vector<string> grid = {
        "w...",
        "o...",
        "r...",
        "d..."};
    // One forward vertical
    EXPECT_EQ(countWordInstances(grid), 1);

    vector<string> grid2 = {
        "...d",
        "...r",
        "...o",
        "...w"};
    // One backward vertical (bottom to top)
    EXPECT_EQ(countWordInstances(grid2), 1);
}

TEST(WordSearchTest, DiagonalAllDirections)
{
    vector<string> grid = {
        "w..d",
        ".o.r",
        "..o.",
        "d..w"};

    EXPECT_EQ(countWordInstances(grid), 4);
}

TEST(WordSearchTest, NoMatchEmptyOrSmall)
{
    EXPECT_EQ(countWordInstances({}), 0);
    EXPECT_EQ(countWordInstances({"wor", "d"}), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}