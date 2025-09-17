#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { int r, c; } Node;

int main(void) {
    int N, M;
    if (scanf("%d", &N) != 1) return 0;
    if (scanf("%d", &M) != 1) return 0;

    int total = N * M;
    int *grid = (int*)malloc(sizeof(int) * total);
    if (!grid) return 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int v; scanf("%d", &v);
            grid[i * M + j] = v;
        }
    }

    int X; scanf("%d", &X);
    int startColor = grid[0];
    int goalColor = grid[(N - 1) * M + (M - 1)];
    if (startColor != goalColor) {
        puts("DEAD");
        free(grid);
        return 0;
    }

    int cap = (2 * X + 1) * (2 * X + 1);
    int (*offsets)[2] = malloc(sizeof(int) * 2 * cap);
    int K = 0;
    for (int dr = -X; dr <= X; ++dr) {
        for (int dc = -X; dc <= X; ++dc) {
            if (dr == 0 && dc == 0) continue;
            if (abs(dr) + abs(dc) <= X) {
                offsets[K][0] = dr;
                offsets[K][1] = dc;
                ++K;
            }
        }
    }

    bool *vis = (bool*)calloc(total, sizeof(bool));
    Node *q = (Node*)malloc(sizeof(Node) * total);
    int qh = 0, qt = 0;

    vis[0] = true;
    q[qt++] = (Node){0, 0};

    bool alive = false;
    while (qh < qt) {
        Node cur = q[qh++];
        if (cur.r == N - 1 && cur.c == M - 1) { alive = true; break; }

        for (int i = 0; i < K; ++i) {
            int nr = cur.r + offsets[i][0];
            int nc = cur.c + offsets[i][1];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            int idx = nr * M + nc;
            if (vis[idx]) continue;
            if (grid[idx] != startColor) continue;
            vis[idx] = true;
            q[qt++] = (Node){nr, nc};
        }
    }

    puts(alive ? "ALIVE" : "DEAD");

    free(q);
    free(vis);
    free(offsets);
    free(grid);
    return 0;
}