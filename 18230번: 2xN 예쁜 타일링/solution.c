#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int ai = *(const int *)a;
    int bi = *(const int *)b;
    return bi - ai;
}

int main(void) {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    int *a = (int *)malloc(A * sizeof(int));
    int *b = (int *)malloc(B * sizeof(int));
    for (int i = 0; i < A; i++) scanf("%d", &a[i]);
    for (int i = 0; i < B; i++) scanf("%d", &b[i]);

    qsort(a, A, sizeof(int), cmp);
    qsort(b, B, sizeof(int), cmp);

    long long *as = (long long *)malloc((A + 1) * sizeof(long long));
    long long *bs = (long long *)malloc((B + 1) * sizeof(long long));
    as[0] = 0;
    for (int i = 1; i <= A; i++) as[i] = as[i - 1] + a[i - 1];
    bs[0] = 0;
    for (int i = 1; i <= B; i++) bs[i] = bs[i - 1] + b[i - 1];
    long long ans = 0;
    int maxS = N / 2 < B ? N / 2 : B;
    for (int x = 0; x <= maxS; x++) {
        int y = N - 2 * x;
        if (y < 0 || y > A) continue;
        long long cur = bs[x] + as[y];
        if (cur > ans) ans = cur;
    }

    printf("%lld\n", ans);
    return 0;
}