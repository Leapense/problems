#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    vector<vector<bool>> blocked(a + 1, vector<bool>(b + 1, false));

    int n;
    cin >> n;
    for (int k = 0; k < n; ++k)
    {
        int x, y;
        cin >> x >> y;
        if (x >= 1 && x <= a && y >= 1 && y <= b)
        {
            blocked[x][y] = true;
        }
    }

    vector<vector<unsigned long long>> dp(a + 1, vector<unsigned long long>(b + 1, 0ULL));

    if (!blocked[1][1]) dp[1][1] = 1ULL;

    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (blocked[i][j]) continue;
            if (i > 1) dp[i][j] += dp[i - 1][j];
            if (j > 1) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[a][b] << "\n";
    return 0;
}