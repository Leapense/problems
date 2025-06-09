#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXC 105

static bool grid[MAXC][MAXC];
static bool next_grid[MAXC][MAXC];

int main(void)
{
    int C;
    if (scanf("%d", &C) != 1) {
        return 1;
    }

    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int R;
        scanf("%d", &R);

        for (int y = 0; y < MAXC; ++y) {
            memset(grid[y], 0, sizeof(grid[y]));
        }

        for (int i = 0; i < R; ++i) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for (int y = y1; y <= y2; ++y) {
                for (int x = x1; x <= x2; ++x) {
                    grid[y][x] = true;
                }
            }
        }

        int seconds = 0;

        while (true) {
            bool anyAlive = false;

            for (int y = 0; y < MAXC; ++y) {
                for (int x = 0; x < MAXC; ++x) {
                    bool cell = grid[y][x];
                    bool north = (y > 0) && grid[y - 1][x];
                    bool west = (x > 0) && grid[y][x - 1];

                    if (cell) {
                        next_grid[y][x] = (north || west);
                    } else {
                        next_grid[y][x] = (north && west);
                    }

                    if (next_grid[y][x]) {
                        anyAlive = true;
                    }
                }
            }

            ++seconds;
            if (!anyAlive) {
                break;
            }

            for (int y = 0; y < MAXC; ++y) {
                memcpy(grid[y], next_grid[y], sizeof(grid[y]));
            }

        }

        printf("Case #%d: %d\n", caseNum, seconds);
    }

    return 0;
}