#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<long long> K(M);
    for (int j = 0; j < M; ++j) cin >> K[j];

    vector<long long> X(N),Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    long long ans = 0;
    vector<long long> B(N);

    for (int j = 0; j < M; ++j) {
        long long k = K[j];
        unordered_map<long long, int> cnt;
        cnt.reserve((size_t)(N * 1.3));

        for (int i = 0; i < N; ++i) {
            long long b = Y[i] - k * X[i];
            ++cnt[b];
        }
        for (const auto &p : cnt) {
            long long c = p.second;
            ans += c * (c - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}