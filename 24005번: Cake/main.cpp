#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> dp(N + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            for (int k = 1; k * k <= i; k++) {
                dp[i] = min(dp[i], dp[i - k * k] + 1);
            }
        }

        cout << "Case #" << t << ": " << dp[N] << "\n";
    }

    return 0;
}
