#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    uint64_t x;
    int m;
    if (scanf("%" SCNu64 " %d", &x, &m) != 2) return 0;
    const uint64_t N = 1000000000000000000ULL;
    const uint64_t total = N - m;

    printf("? 1\n");
    fflush(stdout);
    uint64_t pivot;
    if (scanf("%" SCNu64, &pivot) != 1) return 0;

    uint64_t v_app;
    if (x >= pivot) {
        v_app = x - pivot + 1;
    } else {
        v_app = (N - pivot + 1) + x;
    }

    uint64_t L = (v_app > (uint64_t)m ? v_app - m : 1);
    if (L < 1) L = 1;
    uint64_t R = (v_app <= total ? v_app : total);

    while (L <= R) {
        uint64_t mid = (L + R) / 2;
        printf("? %" PRIu64 "\n", mid);
        fflush(stdout);
        uint64_t val;
        if (scanf("%" SCNu64, &val) != 1) return 0;
        if (val == x) {
            printf("! %" PRIu64 "\n", mid);
            fflush(stdout);
            return 0;
        }
        if (val < x) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    printf("! -1\n");
    fflush(stdout);
    return 0;
}