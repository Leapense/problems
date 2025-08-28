#include <stdio.h>
#include <inttypes.h>

static unsigned long long ceil_div_ull(unsigned long long a, unsigned long long b) {
    return (a + b - 1) / b;
}

static unsigned long long floor_div_ull(unsigned long long a, unsigned long long b) {
    return a / b;
}

int main(void) {
    unsigned long long N, A, L, R;
    if (scanf("%llu %llu %llu %llu", &N, &A, &L, &R) != 4) return 0;
    if (A == 0) {
        if (L == 0) {
            puts("YES");
            for (unsigned long long i = 0; i < N; ++i) {
                printf("0%c", (i + 1 == N) ? '\n' : ' ');
            }
        } else {
            puts("NO");
        }

        return 0;
    }
    __uint128_t n128 = (__uint128_t)N;
    __uint128_t a128 = (__uint128_t)A;
    __uint128_t l128 = (__uint128_t)L;
    __uint128_t r128 = (__uint128_t)R;
    if (a128 < l128 * n128) {
        puts("NO");
        return 0;
    }
    if (a128 > r128 * n128) {
        puts("NO");
        return 0;
    }

    if (R == 0) {
        puts("NO");
        return 0;
    }

    unsigned long long w_lo = ceil_div_ull(A, R);
    if (w_lo == 0) w_lo = 1;
    unsigned long long w_hi = N;
    if (L > 0) {
        unsigned long long t = floor_div_ull(A, L);
        if (t < w_hi) w_hi = t;
    }

    if (w_lo > w_hi) {
        puts("NO");
        return 0;
    }

    unsigned long long w = 0, h = 0;
    for (unsigned long long x = w_lo; x <= w_hi; ++x) {
        if (A % x == 0) {
            unsigned long long hh = A / x;
            if (hh >= L && hh <= R) {
                w = x;
                h = hh;
                break;
            }
        }
    }
    if (w == 0) {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (unsigned long long i = 0; i < N; ++i) {
        unsigned long long val = (i < w) ? h : L;
        printf("%llu%c", val, (i + 1 == N) ? '\n' : ' ');
    }

    return 0;
}