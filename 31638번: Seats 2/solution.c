#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    long long x, c;
    int idx;
} Node;

int cmp_node(const void* a, const void* b) {
    const Node *pa = (const Node*)a, *pb = (const Node*)b;
    if (pa->x < pb->x) return -1;
    if (pa->x > pb->x) return 1;
    if (pa->c < pb->c) return -1;
    if (pa->c > pb->c) return 1;
    return (pa->idx < pb->idx) ? -1 : (pa->idx > pb->idx);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    Node *v = (Node*)malloc(sizeof(Node) * (size_t)N);
    for (int i = 0; i < N; ++i) {
        long long C, X;
        scanf("%lld %lld", &C, &X);
        v[i].x = X; v[i].c = C; v[i].idx = i;
    }
    qsort(v, (size_t)N, sizeof(Node), cmp_node);

    const long long INF = (1LL << 62);
    int *leftDiff = (int*)malloc(sizeof(int) * (size_t)N);
    int *rightDiff = (int*)malloc(sizeof(int) * (size_t)N);
    long long *ans = (long long*)malloc(sizeof(long long) * (size_t)N);

    for (int i = 0; i < N; ++i) {
        if (i == 0) leftDiff[i] = -1;
        else leftDiff[i] = (v[i-1].c != v[i].c) ? (i-1) : leftDiff[i-1];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i == N - 1) rightDiff[i] = -1;
        else rightDiff[i] = (v[i+1].c != v[i].c) ? (i+1) : rightDiff[i+1];
    }

    for (int i = 0; i < N; ++i) {
        long long dl = (leftDiff[i] == -1) ? INF : (v[i].x - v[leftDiff[i]].x);
        long long dr = (rightDiff[i] == -1) ? INF : (v[rightDiff[i]].x - v[i].x);
        ans[v[i].idx] = (dl < dr) ? dl : dr;
    }

    for (int i = 0; i < N; ++i) {
        printf("%lld\n", ans[i]);
    }

    free(v);
    free(leftDiff);
    free(rightDiff);
    free(ans);
    return 0;
}