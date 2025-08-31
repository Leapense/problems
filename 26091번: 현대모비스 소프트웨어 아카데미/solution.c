#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void* p, const void* q) {
    long long x = *(const long long*)p;
    long long y = *(const long long*)q;
    return (x > y) - (x < y);
}

int main(void)
{
    int N;
    long long M;
    if (scanf("%d %lld", &N, &M) != 2) return 0;
    long long* a = (long long*)malloc(sizeof(long long) * (size_t)N);
    if (!a) return 0;
    for (int i = 0; i < N; ++i) scanf("%lld", &a[i]);

    qsort(a, (size_t)N, sizeof(long long), cmp_ll);

    int i = 0;
    int j = N - 1;
    long long teams = 0;
    while (i < j) {
        if (a[i] + a[j] >= M) {
            ++teams;
            ++i;
            --j;
        } else {
            ++i;
        }
    }

    printf("%lld\n", teams);
    free(a);
    return 0;
}