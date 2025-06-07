#include <stdio.h>
#include <stdbool.h>

static int R, C;
static bool visited[10][10];
static const int dr[4] = {-1, 0, +1, 0};
static const int dc[4] = {0, 1, 0, -1};

static int dfs(int r, int c, int dir) {
    visited[r][c] = true;

    int fr = r + dr[dir];
    int fc = c + dc[dir];
    bool canF = fr >= 0 && fr < R && fc >= 0 && fc < C && !visited[fr][fc];

    int rdir = (dir + 1) % 4;
    int rr = r + dr[rdir];
    int rc = c + dc[rdir];
    bool canR = rr >= 0 && rr < R && rc >= 0 && rc < C && !visited[rr][rc];

    int cnt = 0;
    if (!canF && !canR) {
        cnt = 1;
    } else {
        if (canF) cnt += dfs(fr, fc, dir);
        if (canR) cnt += dfs(rr, rc, rdir);
    }

    visited[r][c] = false;
    return cnt;
}

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) return 1;
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                visited[i][j] = false;
            }
        }

        int result = dfs(R-1, 0, 0);
        printf("Case #%d: %d\n", tc, result);
    }

    return 0;
}