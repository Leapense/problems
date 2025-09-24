#include <stdio.h>

int main(void) {
    long long N, M, K;
    if (scanf("%lld %lld %lld", &N, &M, &K) != 3) return 0;

    if (M == N) {
        puts("-1");
        return 0;
    }

    long long S = N - K;
    long long L0 = M - K + 1;

    long long r1 = S + 1;
    printf("%lld", r1);
    
    long long q = S / L0, rem = S % L0;
    long long cur = 1;
    for (long long b = 0; b < L0; ++b) {
        long long sz = q + (b < rem ? 1 : 0);
        for (long long x = cur + sz - 1; x >= cur; --x) {
            printf(" %lld", x);
        }

        cur += sz;
    }

    for (long long v = S + 2; v <= N; ++v) {
        printf(" %lld", v);
    }
    puts("");

    return 0;
}