#include <iostream>
#include <vector>
#include <string>

using namespace std;
const long long mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
                continue;
            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}