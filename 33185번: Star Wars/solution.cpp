#include <bits/stdc++.h>

using namespace std;

void solve(istream &in, ostream &out)
{
    int n, m;
    in >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++)
        in >> a[i];
    const int INF = -1000000;

    vector<vector<int>> dp(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'W')
                dp[i][j] = 0;
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] < 0)
                continue;
            ans = max(ans, dp[i][j]);
            for (int d = -1; d <= 1; d++)
            {
                int ni = i - 1, nj = j + d;
                if (ni >= 0 && nj >= 0 && nj < m && a[ni][nj] != 'W')
                {
                    int add = (a[ni][nj] == 'B');
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + add);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    out << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve(cin, cout);
    return 0;
}