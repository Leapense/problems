#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct { int x, y; } P;

int igcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int cmpP(const void* a, const void* b) {
    const P* p = (const P*)a;
    const P* q = (const P*)b;
    if (p->x != q->x) return (p->x < q->x) ? -1 : 1;
    if (p->y != q->y) return (p->y < q->y) ? -1 : 1;
    return 0;
}

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    P* A = (P*)malloc(sizeof(P) * (size_t)N);
    if (!A) return 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        int g = igcd(x, y);
        A[i].x = x / g;
        A[i].y = y / g;
    }
    qsort(A, (size_t)N, sizeof(P), cmpP);

    int64_t cnt = 0;
    for (int i = 0; i < N; ) {
        ++cnt;
        int j = i + 1;
        while (j < N && A[i].x == A[j].x && A[i].y == A[j].y) ++j;
        i = j;
    }
    printf("%lld\n", (long long)cnt);
    free(A);
    return 0;
}