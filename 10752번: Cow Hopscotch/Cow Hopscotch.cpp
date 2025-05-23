#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<string> grid;
vector<vector<long long>> dp;

long long dfs(int i, int j)
{
    if (i == R - 1 && j == C - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    long long ways = 0;
    for (int ni = i + 1; ni < R; ni++)
    {
        for (int nj = j + 1; nj < C; nj++)
        {
            if (grid[ni][nj] != grid[i][j])
            {
                ways += dfs(ni, nj);
            }
        }
    }

    dp[i][j] = ways;
    return ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    dp.assign(R, vector<long long>(C, -1));
    cout << dfs(0, 0) << "\n";
    return 0;
}