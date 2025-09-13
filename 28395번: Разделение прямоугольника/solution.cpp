#include <bits/stdc++.h>
using namespace std;

static uint64_t isqrt_u128(__uint128_t x) {
    uint64_t lo = 0, hi = uint64_t(1) << 32;
    while(lo + 1 < hi) {
        uint64_t mid = lo + ((hi - lo) >> 1);
        __uint128_t sq = (__uint128_t)mid * (__uint128_t)mid;
        if (sq <= x) lo = mid; else hi = mid;
    }

    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    if (!(cin >> t)) return 0;
    while (t--) {
        uint64_t a, b, k;
        unsigned long long m64;
        cin >> a >> b >> k >> m64;

        __uint128_t m = (__uint128_t)m64;
        __uint128_t S = (__uint128_t)k + 2;
        __uint128_t D = S * S - (__uint128_t)4 * m;

        uint64_t r = isqrt_u128(D);
        if ((__uint128_t)r * r != D) { cout << -1 << '\n'; continue;}

        uint64_t S64 = (uint64_t)S;
        if (((S64 - r) & 1ULL)) { cout << -1 << '\n'; continue; }
        uint64_t x = (S64 - r) / 2ULL;
        uint64_t y = (S64 + r) / 2ULL;

        if (x > y) swap(x, y);
        if (x == 0 || y == 0) { cout << -1 << '\n'; continue; }
        if (x <= a && y <= b) {
            cout << (x - 1) << ' ' << (y - 1) << '\n';
        }  else if (y <= a && x <= b) {
            cout << (y - 1) << ' ' << (x - 1) << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}