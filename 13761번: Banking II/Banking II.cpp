#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pin, pattern;
    cin >> pin >> pattern;
    int n = pin.size();
    int m = pattern.size();

    vector<int> digits(n);
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        digits[i] = pin[i] - '0';
        prefix[i + 1] = prefix[i] + digits[i];
    }

    vector<int> extract(m);

    for (int i = 0; i < m; i++)
    {
        extract[i] = pattern[i] - 'a' + 1;
    }

    const ll NEG_INF = numeric_limits<ll>::min() / 2;
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, NEG_INF));
    dp[0][0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == NEG_INF)
                continue;

            for (int s = j; s + extract[i] <= n; s++)
            {
                ll seg_sum = prefix[s + extract[i]] - prefix[s];
                dp[i + 1][s + extract[i]] = max(dp[i + 1][s + extract[i]], dp[i][j] + seg_sum);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= n; j++)
    {
        ans = max(ans, dp[m][j]);
    }

    cout << ans << "\n";

    return 0;
}