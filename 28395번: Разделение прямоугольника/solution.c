#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

static inline uint64_t isqrt_u128(unsigned __int128 n) {
    if (n == 0) return 0;
    int bl = 0;
    unsigned __int128 tmp = n;
    while (tmp) { tmp >>= 1; ++bl; }
    int e = (bl + 1) >> 1;
    uint64_t x = 1ULL << (e ? (e - 1) : 0);

    for (int i = 0; i < 12; ++i) {
        unsigned __int128 q = n / x;
        uint64_t nx = (uint64_t)((x + q) >> 1);
        if (nx >= x) break;
        x = nx;
    }

    while ((__uint128_t)(x + 1) * (x + 1) <= n) ++x;
    while ((__uint128_t)x * x > n) --x;
    return x;
}

int main(void)
{
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        uint64_t a, b, k;
        unsigned long long m64;
        if (scanf("%" SCNu64 " %" SCNu64 " %" SCNu64 " %llu", &a, &b, &k, &m64) != 4) return 0;
        
        unsigned __int128 m = (unsigned __int128)m64;
        unsigned __int128 S = (unsigned __int128)k + 2u;
        unsigned __int128 D = S * S - (unsigned __int128)4 * m;

        uint64_t r = isqrt_u128(D);
        if ((__uint128_t)r * r != D) {puts("-1"); continue;}

        uint64_t S64 = (uint64_t)S;
        if (((S64 - r) & 1ULL)) {puts("-1"); continue;}

        uint64_t x = (S64 - r) / 2ULL;
        uint64_t y = (S64 + r) / 2ULL;
        if (x > y) {uint64_t t = x; x = y; y = t;}
        if (x == 0 || y == 0) {puts("-1"); continue;}

        if (x <= a && y <= b) {
            printf("%" PRIu64 " %" PRIu64 "\n", x - 1, y - 1);
        } else if (y <= a && x <= b) {
            printf("%" PRIu64 " %" PRIu64 "\n", y - 1, x - 1);
        } else {
            puts("-1");
        }
    }
    return 0;
}