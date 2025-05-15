#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        if (!(cin >> n)) return 0;
        if (n == -1) break;

        vector<string> raw(n);
        for (auto& row : raw) cin >> row;

        vector<vector<u64>> dp(n, vector<u64>(n, 0));
        dp[n-1][n-1] = 1;

        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (r == n - 1 && c == n - 1) continue;
                int k = raw[r][c] - '0';
                if (k == 0) continue;

                if (r + k < n) dp[r][c] += dp[r + k][c];
                if (c + k < n) dp[r][c] += dp[r][c + k];
            }
        }

        cout << dp[0][0] << "\n";
    }

    return 0;
}