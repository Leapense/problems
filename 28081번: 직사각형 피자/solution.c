#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void* a, const void* b) {
    long long x = *(const long long*)a, y = *(const long long*)b;
    return (x < y) ? -1 : (x > y);
}

int main(void) {
    long long W, H, K;
    if (scanf("%lld %lld %lld", &W, &H, &K) != 3) return 0;

    int N;
    scanf("%d", &N);
    long long* y = (long long*)malloc((size_t)N * sizeof(long long));
    for (int i = 0; i < N; ++i) scanf("%lld", &y[i]);

    int M;
    scanf("%d", &M);
    long long* x = (long long*)malloc((size_t)M * sizeof(long long));
    for (int i = 0; i < M; ++i) scanf("%lld", &x[i]);

    long long* xs = (long long*)malloc((size_t)(M + 2) * sizeof(long long));
    long long* ys = (long long*)malloc((size_t)(N + 2) * sizeof(long long));
    xs[0] = 0; for (int i = 0; i < M; ++i) xs[i + 1] = x[i]; xs[M + 1] = W;
    ys[0] = 0; for (int i = 0; i < N; ++i) ys[i + 1] = y[i]; ys[N + 1] = H;

    int Wn = M + 1, Hn = N + 1;
    long long* Wseg = (long long*)malloc((size_t)Wn * sizeof(long long));
    long long* Hseg = (long long*)malloc((size_t)Hn * sizeof(long long));
    for (int i = 0; i < Wn; ++i) Wseg[i] = xs[i + 1] - xs[i];
    for (int j = 0; j < Hn; ++j) Hseg[j] = ys[j + 1] - ys[j];

    qsort(Wseg, (size_t)Wn, sizeof(long long), cmp_ll);
    qsort(Hseg, (size_t)Hn, sizeof(long long), cmp_ll);

    unsigned long long ans = 0ULL;
    int j = Hn - 1;
    for (int i = 0; i < Wn; ++i) {
        while (j >= 0) {
            __int128 prod = (__int128)Wseg[i] * (__int128)Hseg[j];
            if (prod <= (__int128)K) break;
            --j;
        }
        if (j < 0) break;
        ans += (unsigned long long)(j + 1);
    }

    printf("%llu\n", ans);

    free(y); free(x); free(xs); free(ys); free(Wseg); free(Hseg);
    return 0;
}