#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { int *data; int head, tail, cap; } Queue;

static Queue* q_new(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * n);
    q->head = q->tail = 0;
    q->cap = n;
    return q;
}
static bool q_empty(Queue* q) { return q->head == q->tail; }
static void q_push(Queue* q, int v) { q->data[q->tail++] = v; }
static int q_pop(Queue* q) { return q->data[q->head++]; }

int main(void)
{
    int N, M;
    long long A, B;
    if (scanf("%d %d %lld %lld", &N, &M, &A, &B) != 4) return 0;

    int* diff = (int*)calloc(N + 2, sizeof(int));
    for (int i = 0; i < M; ++i)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        if (L < 1) L = 1;
        if (R > N - 1) R = N - 1;
        if (L <= R) {
            diff[L] += 1;
            diff[R + 1] -= 1;
        }
    }

    bool *forbid = (bool*)calloc(N + 1, sizeof(bool));
    int run = 0;
    for (int i = 1; i <= N - 1; ++i) {
        run += diff[i];
        forbid[i] = (run > 0);
    }
    forbid[0] = false;

    int *dist = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i <= N; ++i) dist[i] = -1;

    Queue* q = q_new(N + 5);
    dist[0] = 0;
    q_push(q, 0);

    while (!q_empty(q)) {
        int x = q_pop(q);
        long long yA = x + A;
        if (yA <= N) {
            int y = (int)yA;
            if (y >= 1 && y <= N - 1 && forbid[y]) y = 0;
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                if (y == N) {
                    printf("%d\n", dist[y]);
                    goto done;
                }
                q_push(q, y);
            }
        }

        long long yB = x + B;
        if (yB <= N) {
            int y = (int)yB;
            if (y >= 1 && y <= N - 1 && forbid[y]) y = 0;
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                if (y == N) { printf("%d\n", dist[y]); goto done; }
                q_push(q, y);
            }
        }
    }
    printf("-1\n");
    done:
        free(diff); free(forbid); free(dist); free(q->data); free(q);
    return 0;
}