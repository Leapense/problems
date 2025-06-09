#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static int H, W;
static int alt[MAX][MAX];
static int to_r[MAX][MAX], to_c[MAX][MAX];
static int sink_r[MAX][MAX], sink_c[MAX][MAX];

static inline int min_index(int vals[4], int idxs_r[4], int idxs_c[4]) {
    int best = 0;
    for (int i = 1; i < 4; ++i) {
        if (vals[i] < vals[best]) {
            best = i;
        }
    }

    return best;
}

void compute_flow() {
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            int dirs = 0;
            int vals[4];
            int dr[4] = {-1,  0,  0, +1};  // N, W, E, S
            int dc[4] = { 0, -1, +1,  0};
            int nr[4], nc[4];
            for (int d = 0; d < 4; ++d) {
                nr[d] = r + dr[d];
                nc[d] = c + dc[d];
                if (nr[d] >= 0 && nr[d] < H && nc[d] >= 0 && nc[d] < W) {
                    vals[d] = alt[nr[d]][nc[d]];
                } else {
                    vals[d] = alt[r][c] + 1;  // invalid neighbor
                }
            }
            // find minimum neighbor altitude
            int lowest = alt[r][c];
            for (int d = 0; d < 4; ++d) {
                if (vals[d] < lowest) {
                    lowest = vals[d];
                }
            }
            if (lowest == alt[r][c]) {
                to_r[r][c] = r;
                to_c[r][c] = c;
            } else {
                // pick first direction in N, W, E, S with lowest
                int best = -1;
                for (int d = 0; d < 4; ++d) {
                    if (vals[d] == lowest) {
                        best = d;
                        break;
                    }
                }
                to_r[r][c] = r + dr[best];
                to_c[r][c] = c + dc[best];
            }
        }
    }
}

void find_sink(int r, int c) {
    if (sink_r[r][c] >= 0) {
        return;
    }

    int nr = to_r[r][c], nc = to_c[r][c];
    if (nr == r && nc == c) {
        sink_r[r][c] = r;
        sink_c[r][c] = c;
    } else {
        find_sink(nr, nc);
        sink_r[r][c] = sink_r[nr][nc];
        sink_c[r][c] = sink_c[nr][nc];
    }
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return EXIT_FAILURE;
    }

    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%d", &alt[i][j]);
                sink_r[i][j] = -1;
            }
        }

        compute_flow();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                find_sink(i, j);
            }
        }
        char label_map[MAX][MAX] = {{0}};
        char next_label = 'a';
        printf("Case #%d:\n", tc);

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                int sr = sink_r[i][j];
                int sc = sink_c[i][j];
                if (label_map[sr][sc] == 0) {
                    label_map[sr][sc] = next_label++;
                }

                putchar(label_map[sr][sc]);
                if (j + 1 < W) {
                    putchar(' ');
                }
            }

            putchar('\n');
        }
    }

    return EXIT_SUCCESS;
}