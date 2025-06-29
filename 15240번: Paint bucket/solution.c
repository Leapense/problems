#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int R, C;
    if (scanf("%d %d", &R, &C) != 2) return 0;
    char **grid = malloc(R * sizeof *grid);
    for (int i = 0; i < R; i++) {
        grid[i] = malloc((C + 1) * sizeof *grid[i]);
        scanf("%s", grid[i]);
    }
    int Y, X, K;
    scanf("%d %d %d", &Y, &X, &K);
    char target = grid[Y][X];
    char fill  = (char)('0' + K);
    if (target != fill) {
        size_t maxq = (size_t)R * C;
        int *qy = malloc(maxq * sizeof *qy);
        int *qx = malloc(maxq * sizeof *qx);
        size_t head = 0, tail = 0;
        qy[tail] = Y;  qx[tail++] = X;
        grid[Y][X] = fill;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (head < tail) {
            int cy = qy[head], cx = qx[head++];
            for (int d = 0; d < 4; d++) {
                int ny = cy + dirs[d][0];
                int nx = cx + dirs[d][1];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C && grid[ny][nx] == target) {
                    grid[ny][nx] = fill;
                    qy[tail] = ny;
                    qx[tail++] = nx;
                }
            }
        }
        free(qy);
        free(qx);
    }
    for (int i = 0; i < R; i++) {
        printf("%s\n", grid[i]);
        free(grid[i]);
    }
    free(grid);
    return 0;
}