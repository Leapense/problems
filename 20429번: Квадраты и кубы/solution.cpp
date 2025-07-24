#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = unsigned __int128;

static u64 floorSqrt(u64 v) {
    u64 l = 0, r = 1ull << 32;
    while (l < r) {
        u64 m = (l + r + 1) >> 1;
        if (static_cast<u128>(m) * m <= v) l = m;
        else r = m - 1;
    }
    return l;
}
static u64 ceilSqrt(u64 v) {
    u64 t = floorSqrt(v);
    return t * t == v ? t : t + 1;
}
static u64 floorCbrt(u64 v) {
    u64 l = 0, r = 1'000'001;
    while (l < r) {
        u64 m = (l + r + 1) >> 1;
        if (static_cast<u128>(m) * m * m <= v) l = m;
        else r = m - 1;
    }
    return l;
}
static u64 ceilCbrt(u64 v) {
    u64 t = floorCbrt(v);
    return static_cast<u128>(t) * t * t == v ? t : t + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    u64 a, b, k;
    if (!(cin >> a >> b >> k)) return 0;
    u64 yStart = ceilCbrt(a);
    u64 yEnd = floorCbrt(b);
    u64 ans = 0;
    for (u64 y = yStart; y <= yEnd; ++y) {
        u128 s = static_cast<u128>(y) * y * y;
        u64 s64 = static_cast<u64>(s);
        u64 L = max<u64>(a, s64 > k ? s64 - k : 0);
        u64 R = min<u64>(b, s64 + k);
        if (L > R) continue;
        u64 xl = ceilSqrt(L);
        u64 xr = floorSqrt(R);
        if (xl > xr) continue;
        ans += xr - xl + 1;
    }

    cout << ans << '\n';
    return 0;
}