#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> opponents(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> opponents[i];
    }

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (i < m + 1)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = max(dp[i - 1], dp[i - m] + opponents[i]);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}