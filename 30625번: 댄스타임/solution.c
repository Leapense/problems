#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const int64_t MOD = 1000000007LL;
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    int Ai, Bi;
    int64_t dp0 = 1, dp1 = 0;
    for (int i = 0; i < N; ++i) {
        if (scanf("%d %d", &Ai, &Bi) != 2) return 0;
        int64_t c = (Bi == 0) ? 1 : (M - 1);
        int64_t w = (Bi == 0) ? (M - 1) : 1;
        int64_t ndp0 = (dp0 * (c % MOD)) % MOD;
        int64_t ndp1 = ((dp1 * (c % MOD)) % MOD + (dp0 * (w % MOD)) % MOD) % MOD;
        dp0 = ndp0;
        dp1 = ndp1;
    }

    printf("%lld\n", (dp0 + dp1) % MOD);
    return 0;
}