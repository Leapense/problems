#include <bits/stdc++.h>
using namespace std;

struct Result {
    int amount;
    int coins;
};

Result solveOne(int price, const vector<int>& wallet)
{
    const int maxCoin = *max_element(wallet.begin(), wallet.end());
    const int MAX_SUM = price + maxCoin;

    const int INF = 1e9;
    vector<int> dp(MAX_SUM + 1, INF);
    dp[0] = 0;

    for (int value : wallet) {
        for (int s = MAX_SUM - value; s >= 0; --s) {
            if (dp[s] != INF && dp[s] + 1 < dp[s + value]) dp[s + value] = dp[s] + 1;
        }
    }

    for (int pay = price; pay <= MAX_SUM; ++pay) {
        if (dp[pay] != INF) return {pay, dp[pay]};
    }

    return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int price; cin >> price;
        int n; cin >> n;

        vector<int> wallet(n);
        for (int &v : wallet) cin >> v;

        auto ans = solveOne(price, wallet);
        cout << ans.amount << " " << ans.coins << "\n";
    }

    return 0;
}