#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;

        if (i >= 2) {
            if (a[i - 1] - a[i - 2] <= 20) {
                dp[i] = min(dp[i], dp[i - 2] + 1);
            }
        }

        if (i >= 3) {
            if (a[i - 1] - a[i - 3] <= 10) {
                dp[i] = min(dp[i], dp[i - 3] + 1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}