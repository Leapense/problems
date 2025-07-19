#include <stdio.h>
#include <stdint.h>

static const int DX[4] = {1, 0, -1, 0};
static const int DY[4] = {0, 1, 0, -1};

static int dir_index(char c) {
    return (c == 'R') ? 0 : (c == 'U') ? 1 : (c == 'L') ? 2 : 3;
}

static uint64_t dfs(const char *s, int len, int depth, int x, int y, uint16_t visited) {
    if (depth == len) {
        return 1;
    }
    uint64_t sum = 0;
    int d = dir_index(s[depth]);
    for (int step = 1; step <= 2; ++step) {
        int nx = x + DX[d] * step;
        int ny = y + DY[d] * step;
        if (nx < 0 || nx > 2 || ny < 0 || ny > 2) {
            break;
        }

        int ix1 = x + DX[d] * (step == 2);
        int iy1 = y + DY[d] * (step == 2);
        int id_mid = iy1 * 3 + ix1;
        int id_end = ny * 3 + nx;
        if (step == 2 && (visited & (1u << id_mid))) {
            continue;
        }

        if (visited & (1u << id_end)) {
            continue;
        }

        uint16_t next_v = visited | (1u << id_end);
        if (step == 2) {
            next_v |= (1u << id_mid);
        }

        sum += dfs(s, len, depth + 1, nx, ny, next_v);
    }

    return sum;
}

int main(void)
{
    char s[12];
    if (scanf("%11s", s) != 1) {
        return 0;
    }
    int n = 0;
    while (s[n]) {
        ++n;
    }

    uint64_t total = 0;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            uint16_t vis = 1u << (y * 3 + x);
            total += dfs(s, n, 0, x, y, vis);
        }
    }

    printf("%llu\n", (unsigned long long) total);

    return 0;
}