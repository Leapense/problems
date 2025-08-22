#include <stdio.h>
#define MOD 1000000007

int main(void)
{
    int N;
    scanf("%d", &N);
    long long prev[5] = {0}, curr[5] = {0};
    for (int i = 0; i < 5; i++) {
        prev[i] = 1;
    }
    prev[0] = 1;
    if (N == 1) {
        printf("%lld\n", (prev[0] + prev[1] + prev[2] + prev[3]  + prev[4]) % MOD);
        return 0;
    }
    for (int day = 2; day <= N; day++) {
        curr[0] = (prev[1] + prev[2] + prev[3] + prev[4]) % MOD;
        curr[1] = (prev[0] + prev[3] + prev[4]) % MOD;
        curr[2] = (prev[0] + prev[4]) % MOD;
        curr[3] = (prev[0] + prev[1]) % MOD;
        curr[4] = (prev[0] + prev[1] + prev[2]) % MOD;
        for (int i = 0; i < 5; i++) {
            prev[i] = curr[i];
        }
    }

    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = (ans + prev[i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}