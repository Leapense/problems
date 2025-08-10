#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int iabs(int x) { return x < 0 ? -x : x; }

int main(void) {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;
    int* A = (int*)malloc(sizeof(int) * N);
    if (!A) return 0;
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    bool* visited = (bool*)calloc((size_t)N, sizeof(bool));
    int *q = (int*)malloc(sizeof(int) * N);
    if (!visited || !q) return 0;

    int head = 0, tail = 0;
    visited[0] = true;
    q[tail++] = 0;

    while (head < tail) {
        int i = q[head++];
        if (i == N - 1) {
            puts("YES");
            free(A);
            free(visited);
            free(q);
            return 0;
        }
        int maxJ = i + K;
        if (maxJ >= N) maxJ = N - 1;
        for (int j = i + 1; j <= maxJ; ++j) {
            if (visited[j]) continue;
            int cost = (j - i) * (1 + iabs(A[i] - A[j]));
            if (cost <= K) {
                visited[j] = true;
                q[tail++] = j;
            }
        }
    }
    puts("NO");
    free(A);
    free(visited);
    free(q);
    return 0;
}