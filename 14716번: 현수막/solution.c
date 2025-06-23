#include <stdio.h>
#include <stdlib.h>

enum { MAX_M = 250, MAX_N = 250 };

static int grid[MAX_M][MAX_N];
static int visited[MAX_M][MAX_N];

static const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
static const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

static int M, N;

static void dfs(int r, int c)
{
    visited[r][c] = 1;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
            if (!visited[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc);
            }
        }
    }
}

int main(void)
{
    if (scanf("%d %d", &M, &N) != 2) {
        return 0;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            visited[i][j] = 0;
        }
    }

    int letter_count = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                letter_count++;
                dfs(i, j);
            }
        }
    }

    printf("%d\n", letter_count);
    return 0;
}