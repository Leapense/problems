#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct { int r, c; } Node;

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char **g = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; ++i)
    {
        g[i] = (char*)malloc(sizeof(char) * (N + 1));
        scanf("%s", g[i]);
    }

    int fr = -1, fc = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (g[i][j] == 'F') {
                fr = i;
                fc = j;
            }
        }
    }

    const int dx[7] = {-1,-1,0,0,1,1,1};
    const int dy[7] = {-1,1,-1,1,1,0,-1};

    uint8_t *vis_mem = (uint8_t*)calloc((size_t)N * (size_t)N, sizeof(uint8_t));

    #define VIS(i,j) vis_mem[(size_t)(i)*(size_t)N + (size_t)(j)]

    Node *q = (Node*)malloc(sizeof(Node) * (size_t)N * (size_t)N);
    int qh = 0, qt = 0;

    q[qt++] = (Node){fr, fc};
    VIS(fr, fc) = 1;

    while (qh < qt) {
        Node cur = q[qh++];
        int r = cur.r, c = cur.c;
        for (int k = 0; k < 7; ++k) {
            int nr = r - dx[k];
            int nc = c - dy[k];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (g[nr][nc] == '#') continue;
            if (VIS(nr, nc)) continue;
            VIS(nr, nc) = 1;
            q[qt++] = (Node){nr, nc};
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (g[i][j] == '.' && VIS(i,j)) ++ans;
        }
    }

    printf("%lld\n", ans);

    free(q);
    free(vis_mem);
    for (int i = 0; i < N; ++i) free(g[i]);
    free(g);

    return 0;
}