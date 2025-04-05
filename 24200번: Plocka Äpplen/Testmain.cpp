#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

int N, K;
vector<vector<int>> apples;
int maxSum = 0;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};

void dfs(int r, int c, int count, int sum, vector<vector<bool>> &visited)
{
    if (count <= K)
        maxSum = max(maxSum, sum);
    if (count == K)
        return;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= 2 || nc < 0 || nc >= N)
        {
            continue;
        }
        if (visited[nr][nc])
            continue;

        visited[nr][nc] = true;
        dfs(nr, nc, count + 1, sum + apples[nr][nc], visited);
        visited[nr][nc] = false;
    }
}

int solve(istream &in, ostream &out)
{
    in >> N >> K;
    apples.assign(2, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        in >> apples[0][i];
    }

    for (int i = 0; i < N; i++)
    {
        in >> apples[1][i];
    }

    vector<vector<bool>> visited(2, vector<bool>(N, false));
    visited[1][0] = true;
    maxSum = 0;
    dfs(1, 0, 1, apples[1][0], visited);
    out << maxSum;

    return 0;
}

TEST(PlockaApplenTest, SampleTest1)
{
    string input = "2 2\n7 3\n6 4\n";
    string expected = "13";
    stringstream in(input);
    stringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}