#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static inline int next_char(void) {
    static unsigned char buf[1 << 20];
    static size_t idx = 0, len = 0;
    if (idx >= len) {
        len = fread(buf, 1, sizeof buf, stdin);
        idx = 0;
        if (len == 0) return EOF;
    }

    return buf[idx++];
}

static inline int read_int(void) {
    int c = next_char();
    while (c <= ' ' && c != EOF) c = next_char();
    int x = 0, neg = 0;
    if (c == '-') {
        neg = 1;
        c = next_char();
    }
    for (; c >= '0' && c <= '9'; c = next_char()) {
        x = x * 10 + (c - '0');
    }

    return neg ? -x : x;
}

int main(void) {
    int N = read_int();
    int M = read_int();

    if (N <= 0 || M <= 0) {
        printf("0\n");
        return 0;
    }

    int64_t total = (int64_t)N * M;
    uint32_t *grid = (uint32_t *)malloc(sizeof(uint32_t) * total);
    uint8_t *vis = (uint8_t *)calloc((size_t)total, 1);
    if (!grid || !vis) return 0;

    for (int64_t p = 0; p < total; ++p) {
        int R = read_int(), G = read_int(), B = read_int();
        grid[p] = ((uint32_t)R << 16) | ((uint32_t)G << 8) | (uint32_t)B;
    }

    int *queue = (int *)malloc(sizeof(int) * (size_t)total);
    if (!queue) {
        return 0;
    }

    const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    uint32_t comoponents = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int start = r * M + c;
            if (vis[start]) continue;

            ++comoponents;
            uint32_t color = grid[start];

            int head = 0, tail = 0;
            queue[tail++] = start;
            vis[start] = 1;

            while (head < tail) {
                int v = queue[head++];
                int vr = v / M, vc = v % M;

                for (int k = 0; k < 8; ++k) {
                    int nr = vr + dr[k], nc = vc + dc[k];
                    if ((unsigned)nr < (unsigned)N && (unsigned)nc < (unsigned)M) {
                        int ni = nr * M + nc;
                        if (!vis[ni] && grid[ni] == color) {
                            vis[ni] = 1;
                            queue[tail++] = ni;
                        }
                    }
                }
            }
        }
    }

    printf("%u\n", comoponents);

    free(queue);
    free(vis);
    free(grid);
    return 0;
}