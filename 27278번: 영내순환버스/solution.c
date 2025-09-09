#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    long long *t = (long long*)malloc((size_t)N * sizeof(long long));
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &t[i]);
    }

    long long *a = (long long*)malloc((size_t)(N + 1) * sizeof(long long));
    long long T = 0;
    a[1] = 0;
    for (int s = 2; s <= N; ++s) {
        T += t[s - 2];
        a[s] = T;
    }
    T += t[N - 1];

    long long ans = 0;
    for (int i = 0; i < M; ++i) {
        int p, r;
        long long c;
        scanf("%d %d %lld", &p, &r, &c);

        long long base = a[p];
        long long k = 0;
        if (c > base) {
            long long diff = c - base;
            k = (diff + T - 1) / T;
        }

        long long b = base + k * T;
        long long d = (a[r] - a[p]) % T;
        if (d < 0) d += T;
        long long f = b + d;
        if (f > ans) ans = f;
    }

    printf("%lld\n", ans);
    free(t);
    free(a);

    return 0;
}