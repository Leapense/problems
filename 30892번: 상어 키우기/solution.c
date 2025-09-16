#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static int cmp_ll(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    return (x < y) ? -1 : (x > y);
}

typedef struct {
    long long* data;
    int size;
} MaxHeap;

static void heap_push(MaxHeap* h, long long x) {
    int i = h->size++;
    h->data[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] >= h->data[i]) break;
        long long tmp = h->data[p];
        h->data[p] = h->data[i];
        h->data[i] = tmp;
        i = p;
    }
}

static long long heap_pop(MaxHeap* h) {
    long long ret = h->data[0];
    h->size--;
    if (h->size == 0) return ret;
    h->data[0] = h->data[h->size];
    int i = 0;
    while (1) {
        int l = i * 2 + 1, r = i * 2 + 2, m = i;
        if (l < h->size && h->data[l] > h->data[m]) m = l;
        if (r < h->size && h->data[r] > h->data[m]) m = r;
        if (m == i) break;
        long long tmp = h->data[i];
        h->data[i] = h->data[m];
        h->data[m] = tmp;
        i = m;
    }

    return ret;
}

int main(void) {
    int N, K;
    long long T;
    if (scanf("%d %d %lld", &N, &K, &T) != 3) return 0;

    long long* A = (long long*)malloc(sizeof(long long) * (size_t)N);
    for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
    qsort(A, (size_t)N, sizeof(long long), cmp_ll);

    MaxHeap pq;
    pq.data = (long long*)malloc(sizeof(long long) * (size_t)N);
    pq.size = 0;

    int i = 0;
    while (i < N && A[i] < T) heap_push(&pq, A[i++]);

    for (int step = 0; step < K; ++step) {
        if (pq.size == 0) break;
        T += heap_pop(&pq);
        while (i < N && A[i] < T) heap_push(&pq, A[i++]);
    }

    printf("%lld\n", T);

    free(pq.data);
    free(A);
    return 0;
}