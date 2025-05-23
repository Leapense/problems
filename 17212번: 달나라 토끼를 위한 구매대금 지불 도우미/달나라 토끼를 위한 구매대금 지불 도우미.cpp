#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_coins(int N) {
    vector<int> coins = {1, 2, 5, 7};
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int x = 1; x <= N; ++x) {
        for (int coin : coins) {
            if (x >= coin) {
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;
    cout << min_coins(N) << endl;

    return 0;
}