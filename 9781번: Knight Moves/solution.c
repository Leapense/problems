#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define QUEUE_SIZE (MAX * MAX)

typedef struct {
    int row;
    int col;
} Point;

static const int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
static const int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void)
{
    int n, m;
    char grid[MAX][MAX + 1];
    int dist[MAX][MAX];
    Point queue[QUEUE_SIZE];
    int head = 0, tail = 0;
    Point start = {-1, -1}, goal = {-1, -1};

    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'K') {
                start.row = i;
                start.col = j;
            } else if (grid[i][j] == 'X') {
                goal.row = i;
                goal.col = j;
            }
            dist[i][j] = -1;
        }
    }

    // BFS 초기화
    dist[start.row][start.col] = 0;
    queue[tail++] = start;

    // BFS 순회
    while (head < tail) {
        Point cur = queue[head++];
        if (cur.row == goal.row && cur.col == goal.col)
        {
            break;
        }

        for (int d = 0; d < 8; d++)
        {
            int nr = cur.row + dr[d];
            int nc = cur.col + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (grid[nr][nc] == '#') {
                continue;
            }
            if (dist[nr][nc] != -1) {
                continue;
            }
            dist[nr][nc] = dist[cur.row][cur.col] + 1;
            queue[tail++] = (Point){ nr, nc };
        }
    }

    printf("%d\n", dist[goal.row][goal.col]);
    return 0;
}
