#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;
    vector<int> x(K);

    for (auto &num : x) cin >> num;

    int INF = 1e9;

    int max_cups = 100 + 10 * K;
    vector<int> dp(max_cups + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < K; ++i) {
        vector<int> tmp = dp;
        for (int t = 1; t <= ceil((double)x[i] / 10.0); ++t) {
            int brewed = min(t * 10, x[i]);
            for (int j = 0; j <= max_cups - brewed; ++j) {
                if(dp[j] + t < tmp[j + brewed]) {
                    tmp[j + brewed] = dp[j] + t;
                }
            }
        }
        dp = tmp;
    }

    int result = INF;
    for(int j = N; j <= max_cups; ++j) {
        if (dp[j] < result) {
            result = dp[j];
        }
    }

    cout << result << "\n";

    return 0;
}