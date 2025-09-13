#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long MOD = 1'000'000'007LL;
    int N, M;
    if (!(cin >> N >> M)) return 0;

    long long dp0 = 1, dp1 = 0;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        long long c = (B == 0) ? 1 : (M - 1);
        long long w = (B == 0) ? (M - 1) : 1;
        long long ndp0 = (dp0 * (c % MOD)) % MOD;
        long long ndp1 = ((dp1 * (c % MOD)) % MOD + (dp0 * (w % MOD)) % MOD) % MOD;
        dp0 = ndp0;
        dp1 = ndp1;
    }
    cout << (dp0 + dp1) % MOD << '\n';
    return 0;
}