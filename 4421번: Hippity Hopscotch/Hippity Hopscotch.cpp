#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> grid;
vector<vector<int>> dp;

int dfs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int best = 0;
    for (int d = 1; d <= k; d++)
    {
        if (i + d < n && grid[i + d][j] > grid[i][j])
            best = max(best, dfs(i + d, j));
        if (i - d >= 0 && grid[i - d][j] > grid[i][j])
            best = max(best, dfs(i - d, j));
        if (j + d < n && grid[i][j + d] > grid[i][j])
            best = max(best, dfs(i, j + d));
        if (j - d >= 0 && grid[i][j - d] > grid[i][j])
            best = max(best, dfs(i, j - d));
    }

    dp[i][j] = grid[i][j] + best;
    return dp[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    grid.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << dfs(0, 0) << "\n";
    return 0;
}