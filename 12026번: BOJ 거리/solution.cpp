#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX / 4;

inline char nextChar(char c) {
    switch (c) {
        case 'B': return 'O';
        case 'O': return 'J';
        default: return 'B';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string blocks;
    blocks.reserve(N);
    cin >> blocks;

    vector<long long> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        if (dp[i] == INF) {
            continue;
        }

        char required = nextChar(blocks[i]);
        for (int j = i + 1; j < N; j++) {
            if (blocks[j] != required) {
                continue;
            }
            long long distance = static_cast<long long>(j - i);
            long long cost = distance * distance;
            long long candidate = dp[i] + cost;
            if (candidate < dp[j]) {
                dp[j] = candidate;
            }
        }
    }

    if (dp[N - 1] == INF) {
        cout << "-1\n";
    } else {
        cout << dp[N - 1] << "\n";
    }

    return 0;
}