#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> dp(n, false);
    string row;

    for (int i = 0; i < n; i++)
    {
        cin >> row;
        vector<bool> next_dp(n, false);
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '.')
            {
                if (i == 0 && j == 0)
                {
                    next_dp[j] = true;
                }
                else
                {
                    bool from_up = (i > 0 && dp[j]);
                    bool from_left = (j > 0 && next_dp[j - 1]);
                    next_dp[j] = (from_up || from_left);
                }
            }
            else
            {
                next_dp[j] = false;
            }
        }
        dp = move(next_dp);
    }

    cout << (dp[n - 1] ? "Yes\n" : "No\n");
    return 0;
}