#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

int main(void) {
    int N;
    int64_t S;
    if (scanf("%d %ld", &N, &S) != 2) return 0;
    int64_t min_cost = LLONG_MAX / 4;
    __int128 total = 0;
    for (int i = 0; i < N; ++i) {
        long Ci, Yi;
        if (scanf("%ld %ld", &Ci, &Yi) != 2) return 0;
        int64_t produce_now = Ci;
        int64_t carry_over = (min_cost <= LLONG_MAX / 4) ? min_cost + S : produce_now;
        if (carry_over < produce_now) min_cost = carry_over; else min_cost = produce_now;
        total += (__int128)min_cost * (__int128)Yi;
    }
    long long out = (long long)total;
    printf("%lld\n", out);
    return 0;
}