#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 105

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char arrows[4] = {'^', '>', 'v', '<'};

int R, C;
char grid[MAX][MAX];

bool has_arrow_in_direction(int x, int y, int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    while (nx >= 0 && nx < R && ny >= 0 && ny < C) {
        if (grid[nx][ny] != '.') return true;
        nx += dx[dir];
        ny += dy[dir];
    }

    return false;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; ++i) {
            scanf("%s", grid[i]);
        }

        bool impossible = false;
        int answer = 0;
        for (int i = 0; i < R && !impossible; ++i) {
            for (int j = 0; j < C; ++j) {
                char c = grid[i][j];
                if (c == '.') continue;
                int dir;
                for (dir = 0; dir < 4; ++dir) {
                    if (arrows[dir] == c) break;
                }

                if (has_arrow_in_direction(i, j, dir)) continue;
                bool possible = false;
                for (int d = 0; d < 4; ++d) {
                    if (d == dir) continue;
                    if (has_arrow_in_direction(i, j, d)) {
                        possible = true;
                        break;
                    }
                }
                if (!possible) {
                    impossible = true;
                    break;
                }

                answer++;
            }
        }

        if (impossible) {
            printf("Case #%d: IMPOSSIBLE\n", t);
        } else {
            printf("Case #%d: %d\n", t, answer);
        }
    }

    return 0;
}