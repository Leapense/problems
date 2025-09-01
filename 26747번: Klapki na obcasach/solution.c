#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

static int cmp_ll(const void* a, const void* b) {
    int64_t x = *(const int64_t*)a;
    int64_t y = *(const int64_t*)b;
    return (x > y) - (x < y);
}

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int64_t* H = (int64_t*)malloc((size_t)N * sizeof(int64_t));
    for (int i = 0; i < N; ++i) scanf("%" SCNd64, &H[i]);

    int M;
    scanf("%d", &M);
    int64_t* A = NULL;
    if (M > 0) {
        A = (int64_t*)malloc((size_t)M * sizeof(int64_t));
        for (int j = 0; j < M; ++j) scanf("%" SCNd64, &A[j]);
    }

    int64_t T;
    scanf("%" SCNd64, &T);

    int64_t base = 0;
    int need_cnt = 0;
    for (int i = 0; i < N; ++i) if (H[i] >= T) ++base;
    for (int i = 0; i < N; ++i) if (H[i] < T) ++need_cnt;

    int64_t* need = NULL;
    if (need_cnt > 0) need = (int64_t*) malloc((size_t)need_cnt * sizeof(int64_t));
    int k = 0;
    for (int i = 0; i < N; ++i) if (H[i] < T) need[k++] = T - H[i];

    if (need_cnt > 0) qsort(need, (size_t)need_cnt, sizeof(int64_t), cmp_ll);
    if (M > 0) qsort(A, (size_t)M, sizeof(int64_t), cmp_ll);

    int64_t match = 0;
    int i = 0, j = 0;
    while (i < need_cnt && j < M) {
        if (A[j] >= need[i]) {
            ++match;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    printf("%" PRId64 "\n", base + match);

    free(H);
    free(A);
    free(need);
    return 0;
}