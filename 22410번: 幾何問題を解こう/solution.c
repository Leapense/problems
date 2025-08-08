#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

static uint64_t gcd_u64(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    uint64_t p, q;
    if (scanf("%" SCNu64 " %" SCNu64, &p, &q) != 2) return 0;
    uint64_t g = gcd_u64(p, q);
    uint64_t r = q / g;
    if (r == 1) {
        printf("2\n");
        return 0;
    }
    uint64_t ans = 1;
    for (uint64_t d = 2; d * d <= r; ++d) {
        if (r % d == 0) {
            ans *= d;
            while (r % d == 0) r /= d;
        }
    }
    if (r > 1) ans *= r;
    printf("%" PRIu64 "\n", ans);
    return 0;
}