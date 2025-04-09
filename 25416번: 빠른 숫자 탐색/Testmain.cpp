#include <iostream>
#include <sstream>
#include <queue>
#include <tuple>
#include <array>
#include <gtest/gtest.h>

using namespace std;

void solve(istream &in, ostream &out)
{
    array<array<int, 5>, 5> board;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            in >> board[i][j];
        }
    }

    int sr, sc;
    in >> sr >> sc;
    queue<tuple<int, int, int>> q;
    array<array<bool, 5>, 5> vis = {false};
    q.push({sr, sc, 0});
    vis[sr][sc] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [r, c, dist] = q.front();
        q.pop();

        if (board[r][c] == 1)
        {
            out << dist;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !vis[nr][nc] && board[nr][nc] != -1)
            {
                vis[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }

    out << -1;
}

TEST(FastSearchTest, SampleInput1)
{
    string input = "0 0 1 0 0\n0 0 -1 0 0\n0 0 0 0 0\n0 0 -1 0 0\n0 0 0 -1 0\n1 1\n";
    string expected = "2";
    stringstream ss(input), ss_out;
    solve(ss, ss_out);
    EXPECT_EQ(ss_out.str(), expected);
}
TEST(FastSearchTest, SampleInput2)
{
    string input = "0 0 -1 0 0\n0 0 -1 0 0\n0 0 -1 0 0\n0 0 -1 0 0\n0 0 -1 0 1\n1 1\n";
    string expected = "-1";
    stringstream ss(input), ss_out;
    solve(ss, ss_out);
    EXPECT_EQ(ss_out.str(), expected);
}
TEST(FastSearchTest, TargetAtStart)
{
    string input = "1 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0 0 0 0\n0 0\n";
    string expected = "0";
    stringstream ss(input), ss_out;
    solve(ss, ss_out);
    EXPECT_EQ(ss_out.str(), expected);
}
TEST(FastSearchTest, ObstructedPath)
{
    string input = "0 -1 1 0 0\n0 -1 0 0 0\n0 -1 0 0 0\n0 -1 0 0 0\n0 -1 0 0 0\n0 0\n";
    string expected = "-1";
    stringstream ss(input), ss_out;
    solve(ss, ss_out);
    EXPECT_EQ(ss_out.str(), expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}