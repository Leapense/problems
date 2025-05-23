#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> importance(N);

    for (auto &x : importance) cin >> x;

    vector<vector<long long>> dp(N + 1, vector<long long> (K + 1, 0));
    vector<vector<int>> path(N + 1, vector<int> (K + 1, -1));

    for(int i = 1; i <= N; i++) {
        for(int k = 0; k <= K; k++) {
            if (dp[i][k] < dp[i-1][k]) {
                dp[i][k] = dp[i-1][k];
                path[i][k] = -1;
            }
            if (k > 0) {
                if(dp[i][k] < dp[i - 1][k - 1] + (long long) importance[i - 1] * importance[i - 1]) {
                    dp[i][k] = dp[i-1][k-1] + (long long) importance[i-1] * importance[i-1];
                    path[i][k] = -2;
                }
            }

            for (int j = 1; j < i; j++) {
                if (k > 0) {
                    if (dp[i][k] < dp[j - 1][k - 1] + (long long) importance[j - 1] * importance[i - 1]) {
                        bool valid = true;
                        dp[i][k] = dp[j - 1][k - 1] + (long long) importance[j - 1] * importance[i - 1];
                        path[i][k] = j;
                    }
                }
            }
        }
    }

    long long max_val = 0;

    int best_k = 0;

    for (int k = 0; k <= K; k++) {
        if (dp[N][k] > max_val) {
            max_val = dp[N][k];
            best_k = k;
        }
    }
    vector<pair<int, int>> connections;

    int i = N, k = best_k;
    vector<int> share(N, 0);
    while (i > 0 && k >= 0) {
        if (path[i][k] == -1) {
            i--;
        } else if (path[i][k] == -2) {
            connections.emplace_back(i, 0);
            share[i - 1] = i;
            i--;
            k--;
        } else {
            int j = path[i][k];
            connections.emplace_back(j, i);
            share[j - 1] = i;
            share[i - 1] = j;
            i = j - 1;
            k--;
        }
    }

    while (connections.size() < K) {
        connections.emplace_back(0, 0);
    }

    for (auto & [a, b] : connections) {
        if (a == 0 && b == 0) cout << 0 << "\n";
        else if (b == 0) cout << a << "\n";
        else cout << a << " " << b << "\n";
    }

    for (int i = 0; i < N; i++) cout << share[i] << "\n";

    return 0;
}