#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int C, V, L;
        cin >> C >> V >> L;

        vector<vector<long long>> dp(L + 1, vector<long long>(2, 0));

        dp[1][0] = V;
        dp[1][1] = 0;

        for (int i = 2; i <= L; ++i) {
            dp[i][0] = (dp[i - 1][0] * V + dp[i - 1][1] * V) % MOD;
            dp[i][1] = (dp[i - 1][0] * C) % MOD;
        }

        long long result = (dp[L][0] + dp[L][1]) % MOD;
        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}