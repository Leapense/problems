#include <stdio.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long cnt[3] = {0, 0, 0};

    for (int i = 0; i < N; ++i) {
        long long a;
        scanf("%lld", &a);
        cnt[a % 3]++;
    }

    long long p = cnt[1] - cnt[2];
    long long q = cnt[0] - cnt[2];
    printf("%.9f %.9f\n", (double)p, (double)q);
    return 0;
}