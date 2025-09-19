#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int cmp_ll(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    return (x < y) ? -1 : (x > y);
}

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    
    long long* K = malloc(sizeof(long long) * (size_t)M);
    for (int j = 0; j < M; ++j) scanf("%lld", &K[j]);

    long long* X = malloc(sizeof(long long) * (size_t)N);
    long long* Y = malloc(sizeof(long long) * (size_t)N);
    for (int i = 0; i < N; ++i) scanf("%lld %lld", &X[i], &Y[i]);

    long long* B = malloc(sizeof(long long) * (size_t)N);
    long long ans = 0;

    for (int j = 0; j < M; ++j) {
        long long k = K[j];
        for (int i = 0; i < N; ++i) {
            B[i] = Y[i] - k * X[i];
        }

        qsort(B, (size_t)N, sizeof(long long), cmp_ll);

        long long c = 1;
        for (int i = 1; i < N; ++i) {
            if (B[i] == B[i - 1]) {
                ++c;
            } else {
                ans += c * (c - 1);
                c = 1;
            }
        }

        ans += c * (c - 1);
    }

    printf("%lld\n", ans);

    free(B);
    free(Y);
    free(X);
    free(K);
    return 0;
}