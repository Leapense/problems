#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIM 1001
#define EMPTY 0
#define VISITED 1
#define OBSTACLE 2

int grid[MAX_DIM][MAX_DIM];
int R, C;

const int dr[] = {0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, -1, 1};

bool is_valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void solve() {
    setvbuf(stdin, NULL, _IOFBF, 1 << 20);
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);

    scanf("%d %d", &R, &C);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int br, bc;
        scanf("%d %d", &br, &bc);
        grid[br][bc] = OBSTACLE;
    }

    int curr_r, curr_c;
    scanf("%d %d", &curr_r, &curr_c);
    grid[curr_r][curr_c] = VISITED;

    int directions[4];
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &directions[i]);
    }

    int dir_idx = 0;
    while (true) {
        bool can_move_at_all = false;
        for (int i = 0; i < 4; ++i) {
            int d = directions[i];
            int next_r = curr_r + dr[d];
            int next_c = curr_c + dc[d];
            if (is_valid(next_r, next_c) && grid[next_r][next_c] == EMPTY) {
                can_move_at_all = true;
                break;
            }
        }

        if (!can_move_at_all) {
            break;
        }

        int current_direction = directions[dir_idx];
        while (true) {
            int next_r = curr_r + dr[current_direction];
            int next_c = curr_c + dc[current_direction];

            if (is_valid(next_r, next_c) && grid[next_r][next_c] == EMPTY) {
                curr_r = next_r;
                curr_c = next_c;
                grid[curr_r][curr_c] = VISITED;
            } else {
                break;
            }
        }

        dir_idx = (dir_idx + 1) % 4;
    }
    printf("%d %d\n", curr_r, curr_c);
}

int main() {
    solve();
    return 0;
}