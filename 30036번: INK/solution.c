#include <stdio.h>
#include <ctype.h>

int I, N, K;

int inb (int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int isObs (char c) {
    return c == '#' || (c >= 'A' && c <= 'Z');
}

int main(void)
{
    if (scanf("%d %d %d", &I, &N, &K) != 3) return 0;
    char ink[205], cmd[205];
    char g[105][105];
    scanf("%s", ink);
    int sy = -1, sx = -1;
    for (int i = 0; i < N; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < N; j++) {
            if (g[i][j] == '@') { sy = i; sx = j; g[i][j] = '.'; }
        }
    }

    scanf("%s", cmd);

    int ink_amt = 0, jump_cnt = 0;
    for (char *p = cmd; *p; ++p) {
        char c = *p;
        if (c == 'j') { ink_amt++; }
        else if (c == 'J') {
            char col = ink[jump_cnt % I];
            for (int dy = -ink_amt; dy <= ink_amt; ++dy) {
                int rem = ink_amt - (dy < 0 ? -dy : dy);
                for (int dx = -rem; dx <= rem; ++dx) {
                    int ny = sy + dy, nx = sx + dx;
                    if (!inb(ny, nx)) continue;
                    if (isObs(g[ny][nx])) g[ny][nx] = col;
                }
            }

            ink_amt = 0;
            jump_cnt++;
        } else {
            int dy = 0, dx = 0;
            if (c == 'U') dy = -1;
            else if (c == 'D') dy = 1;
            else if (c == 'L') dx = -1;
            else if (c == 'R') dx = 1;
            int ny = sy + dy, nx = sx + dx;
            if (inb(ny, nx) && !isObs(g[ny][nx])) { sy = ny; sx = nx; }
        }
    }

    g[sy][sx] = '@';
    for (int i = 0; i < N; i++) printf("%s\n", g[i]);
    return 0;
}