#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

typedef unsigned __int128 u128;
static uint64_t floorSqrt(uint64_t v) {
    uint64_t l = 0, r = 1ull << 32;
    while (l < r) {
        uint64_t m = (l + r + 1) >> 1;
        if ((u128)m * m <= v) l = m;
        else r = m - 1;
    }
    return l;
}
static uint64_t ceilSqrt(uint64_t v) {
    uint64_t t = floorSqrt(v);
    return t * t == v ? t : t + 1;
}
static uint64_t floorCbrt(uint64_t v) {
    uint64_t l = 0, r = 1000001;
    while (l < r) {
        uint64_t m = (l + r + 1) >> 1;
        if ((u128)m * m * m <= v) l = m;
        else r = m - 1;
    }

    return l;
}
static uint64_t ceilCbrt(uint64_t v) {
    uint64_t t = floorCbrt(v);
    return (u128)t * t * t == v ? t : t + 1;
}
int main(void) {
    uint64_t a, b, k;
    if (scanf("%" SCNu64 "%" SCNu64 "%" SCNu64, &a, &b, &k) != 3) return 0;
    uint64_t yStart = ceilCbrt(a);
    uint64_t yEnd = floorCbrt(b);
    uint64_t ans = 0;
    for (uint64_t y = yStart; y <= yEnd; ++y) {
        u128 s = (u128)y * y * y;
        uint64_t s64 = (uint64_t)s;
        uint64_t L = a > s64 - (k > s64 ? s64 : k) ? a : s64 - (k > s64 ? s64 : k);
        uint64_t R = b < s64 + k ? b : s64 + k;
        if (L > R) continue;
        uint64_t xl = ceilSqrt(L);
        uint64_t xr = floorSqrt(R);
        if (xl > xr) continue;
        ans += xr - xl + 1;
    }

    printf("%" PRIu64 "\n", ans);
    return 0;
}