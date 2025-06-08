#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_ZOMBIES 8

typedef struct {
    int32_t x;
    int32_t y;
    int32_t appear_time;
} Zombie;

int chebyshev(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return dx > dy ? dx : dy;
}

int max_smashed(int z, Zombie zombies[MAX_ZOMBIES], int perm[MAX_ZOMBIES], bool used[MAX_ZOMBIES], int depth, int cur_x, int cur_y, int64_t cur_time, int64_t cooldown_end) {
    if (depth == z) {
        return 0;
    }

    int max_cnt = 0;
    for (int i = 0; i < z; ++i) {
        if (used[i]) {
            continue;
        }

        Zombie *zb = &zombies[i];
        int move_time = chebyshev(cur_x, cur_y, zb->x, zb->y) * 100;
        int64_t arrival_time = cur_time + move_time;
        if (arrival_time < zb->appear_time) {
            arrival_time = zb->appear_time;
        }
        if (arrival_time < cooldown_end) {
            arrival_time = cooldown_end;
        }

        if (arrival_time > zb->appear_time + 1000) {
            continue;
        }

        used[i] = true;
        int cnt = 1 + max_smashed(z, zombies, perm, used, depth + 1, zb->x, zb->y, arrival_time, arrival_time + 750);
        if (cnt > max_cnt) {
            max_cnt = cnt;
        }

        used[i] = false;
    }

    return max_cnt;
}

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) {
        return 1;
    }

    for (int test_case = 1; test_case <= T; ++test_case) {
        int z;
        if (scanf("%d", &z) != 1) {
            return 1;
        }
        Zombie zombies[MAX_ZOMBIES];
        for (int i = 0; i < z; ++i) {
            if (scanf("%d %d %d", &zombies[i].x, &zombies[i].y, &zombies[i].appear_time) != 3) {
                return 1;
            }
        }

        int perm[MAX_ZOMBIES] = {0};
        bool used[MAX_ZOMBIES] = {false};
        int answer = max_smashed(z, zombies, perm, used, 0, 0, 0, 0, 0);
        printf("Case #%d: %d\n", test_case, answer);
    }

    return 0;
}