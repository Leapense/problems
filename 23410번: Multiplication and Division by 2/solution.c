#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

static bool reachable(uint64_t x, uint64_t y) {
    if (y == 0) {
        return true;
    }

    for (uint32_t s = 0; s <= 32; s++) {
        for (uint32_t m = 0; m <= 32 - s; m++) {
            uint64_t mask = (m == 0) ? 0ULL : ((1ULL << m) - 1ULL);
            uint64_t seg = (x >> s) & mask;
            for (uint32_t p = 0; p <= 32 - m; p++) {
                uint64_t cand = seg << p;
                if (cand == y) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main(void)
{
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    for (int i = 0; i < t; i++) {
        uint64_t x, y;
        if (scanf("%" SCNu64 " %" SCNu64, &x, &y) != 2) {
            return 0;
        }
        x &= 0xFFFFFFFFULL;
        y &= 0xFFFFFFFFULL;
        bool ok = reachable(x, y);
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}