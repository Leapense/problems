#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum { MAXT = 200000 };

typedef struct {
    int *data;
    int size;
    int cap;
    int head;
} Vec;

static void vec_init(Vec *v) {
    v->data = NULL;
    v->size = 0;
    v->cap = 0;
    v->head = 0;
}

static void vec_push(Vec *v, int x) {
    if (v->size == v->cap) {
        int ncap = v->cap ? v->cap * 2 : 2;
        int *nd = (int*)realloc(v->data, sizeof(int) * ncap);
        if (!nd) { perror("realloc"); exit(1); }
        v->data = nd; v->cap = ncap;
    }
    v->data[v->size++] = x;
}

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    Vec *vec = (Vec*)malloc(sizeof(Vec) * (MAXT + 1));
    if (!vec) { perror("malloc"); return 1; }
    for (int t = 0; t <= MAXT; ++t) vec_init(&vec[t]);

    long long *ans = (long long*)calloc(N + 1, sizeof(long long));
    if (!ans) { perror("calloc"); return 1; }

    for (int i = 1; i <= N; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int t;
            scanf("%d", &t);
            vec_push(&vec[t], i);
        }
    }

    for (int j = 0; j < M; ++j) {
        int t;
        scanf("%d", &t);
        Vec *v = &vec[t];
        if (v->head < v->size) {
            int i = v->data[v->head++];
            ans[i] += 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (i > 1) putchar(' ');
        printf("%lld", ans[i]);
    }

    putchar('\n');

    for (int t = 0; t <= MAXT; ++t) free(vec[t].data);
    free(vec);
    free(ans);

    return 0;
}