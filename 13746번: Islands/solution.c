#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 51

typedef struct {
    int r, c;
} Point;

char grid[MAX_DIM][MAX_DIM];
bool visited[MAX_DIM][MAX_DIM];
Point queue[MAX_DIM * MAX_DIM];
int front, rear;

void bfs(int start_r, int start_c, int r_max, int c_max) {
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    front = rear = 0;
    queue[rear++] = (Point){start_r, start_c};
    visited[start_r][start_c] = true;

    while (front < rear) {
        Point curr = queue[front++];
        for (int i = 0; i < 4; ++i) {
            int next_r = curr.r + dr[i];
            int next_c = curr.c + dc[i];

            if (next_r >= 0 && next_r < r_max &&
                next_c >= 0 && next_c < c_max &&
                !visited[next_r][next_c] && grid[next_r][next_c] != 'W') {
                    visited[next_r][next_c] = true;
                    queue[rear++] = (Point){next_r, next_c};
                }
        }
    }
}

void solve() {
    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return;

    for (int i = 0; i < r; ++i) {
        scanf("%s", grid[i]);
    }

    memset(visited, false, sizeof(visited));
    int island_count = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'L' && !visited[i][j]) {
                island_count++;
                bfs(i, j, r, c);
            }
        }
    }
    printf("%d\n", island_count);
}

int main() {
    solve();
    return 0;
}