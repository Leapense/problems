#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int dyn2idx(const char *s) {
    if (!strcmp(s, "ppp")) return 0;
    if (!strcmp(s, "pp")) return 1;
    if (!strcmp(s, "p")) return 2;
    if (!strcmp(s, "mp")) return 3;
    if (!strcmp(s, "mf")) return 4;
    if (!strcmp(s, "f")) return 5;
    if (!strcmp(s, "ff")) return 6;
    return 7;
}

static int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long*) a;
    long long y = *(const long long*) b;
    return (x < y) ? -1 : (x > y);
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    long long *a = (long long*)malloc(sizeof(long long) * (size_t)n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    int *starts = (int*)malloc(sizeof(int) * (size_t)m);
    int *levv = (int*)malloc(sizeof(int) * (size_t)m);

    for (int k = 0; k < m; ++k) {
        int idx;
        char buf[8];
        scanf("%d %7s", &idx, buf);
        starts[k] = idx - 1;
        levv[k] = dyn2idx(buf);
    }

    int *lev = (int*)malloc(sizeof(int) * (size_t)n);
    for (int k = 0; k < m; ++k) {
        int L = starts[k];
        int R = (k + 1 < m ? starts[k + 1] : n) - 1;
        for (int i = L; i <= R; ++i) lev[i] = levv[k];
    }

    long long *bucket[8];
    int cnt[8] = {0};
    for (int i = 0; i < 8; ++i) {
        bucket[i] = (long long*)malloc(sizeof(long long) * (size_t)n);
    }

    for (int i = 0; i < n; ++i) {
        int t = lev[i];
        bucket[t][cnt[t]++] = a[i];
    }

    for (int i = 0; i < 8; ++i) {
        qsort(bucket[i], (size_t)cnt[i], sizeof(long long), cmp_ll);
    }

    long long ans = 0;
    for (int l = 0; l < 8; ++l) {
        for (int r = l + 1; r < 8; ++r) {
            long long *L = bucket[l], *R = bucket[r];
            int nL = cnt[l], nR = cnt[r];
            int i = 0;
            for (int j = 0; j < nR; ++j) {
                long long y = R[j];
                while (i < nL && L[i] < y) ++i;
                ans += (long long)(nL - i);
            }
        }
    }

    printf("%lld\n", ans);

    for (int i = 0; i < 8; ++i) free(bucket[i]);
    free(lev);
    free(levv);
    free(starts);
    free(a);
    return 0;
}