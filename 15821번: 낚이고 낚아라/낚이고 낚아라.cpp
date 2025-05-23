#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> R2 (N, 0);
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi;
        long long maxr = 0;
        for (int j = 0; j < Pi; j++) {
            long long x, y;
            cin >> x >> y;
            long long d = (long long)x * x + (long long)y * y;
            if (d > maxr) maxr = d;
        }
        R2[i] = maxr;
    }
    nth_element(R2.begin(), R2.begin() + K - 1, R2.end());
    long long res = R2[K - 1];
    cout << fixed << setprecision(2) << (double)res << "\n";

    return 0;
}