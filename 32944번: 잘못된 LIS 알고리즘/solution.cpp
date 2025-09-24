#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    if (M == N) {
        cout << -1 << '\n';
        return 0;
    }

    long long S = N - K;
    long long L0 = M - K + 1;

    long long r1 = S + 1;
    cout << r1;

    long long q = S / L0, rem = S % L0;
    long long cur = 1;
    for (long long b = 0; b < L0; ++b) {
        long long sz = q + (b < rem ? 1 : 0);
        for (long long x = cur + sz - 1; x >= cur; --x) {
            cout << ' ' << x;
        }

        cur += sz;
    }

    for (long long v = S + 2; v <= N; ++v) {
        cout << ' ' << v;
    }

    cout << '\n';
    return 0;
}