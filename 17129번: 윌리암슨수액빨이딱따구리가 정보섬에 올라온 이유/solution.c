#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    char *grid = (char *)malloc(n * (size_t)m + 1);
    for (int i = 0; i < n; i++) scanf("%s", grid + i * m);
    int sx = 0, sy = 0;
    for (int i = 0; i < n * m; i++) if (grid[i] == '2') { sx = i / m; sy = i % m; }
    int *dq = (int *)malloc(sizeof(int) * n * m * 2);
    int *dist = (int *)malloc(sizeof(int) * n * m);
    for (int i = 0; i < n * m; i++) dist[i] = -1;
    int head = 0, tail = 0;
    dq[tail * 2] = sx; dq[tail * 2 + 1] = sy; tail++;
    dist[sx * m + sy] = 0;
    int found[3] = {0};
    int best = n * m + 1;
    while (head < tail) {
        int x = dq[head * 2], y = dq[head * 2 + 1];
        head++;
        int d = dist[x * m + y];
        char c = grid[x * m + y];
        if (c >= '3' && c <= '5')
        {
            int idx = c - '3';
            if (!found[idx])
            {
                found[idx] = 1;
                if (d < best) best = d;
            }
        }
        if (found[0] && found[1] && found[2]) break;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int ni = nx * m + ny;
            if (dist[ni] >= 0) continue;
            char cc = grid[ni];
            if (cc == '1') continue;
            dist[ni] = d + 1;
            dq[tail * 2] = nx;
            dq[tail * 2 + 1] = ny;
            tail++;
        }
    }

    if (best <= n * m) printf("TAK\n%d\n", best);
    else printf("NIE\n");
    return 0;
}