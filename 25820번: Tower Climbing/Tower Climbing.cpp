#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    const ll INF = 1e18;
    vector<ll> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n && j <= i + k; j++)
        {
            ll jump_cost = abs(x[i] - x[j]) + (j - i) * (j - i);
            dp[j] = min(dp[j], dp[i] + jump_cost);
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}