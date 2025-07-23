#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int R, S;
    if (scanf("%d %d", &R, &S) != 2) return 0;
    char **g = (char **)malloc(R * sizeof(*g));
    for (int i = 0; i < R; ++i) {
        g[i] = (char *)malloc(S + 1);
        scanf("%s", g[i]);
    }

    int sr = -1, sc = -1;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            if (g[i][j] == 'o') {
                sr = i;
                sc = j;
            }
        }
    }

    const int dr4[4] = {-1, 0, 1, 0};
    const int dc4[4] = {0, 1, 0, -1};
    const char dir4[4] = {'N', 'E', 'S', 'W'};
    int bestLen = 1e9;
    char bestDir = 0;
    for (int d = 0; d < 4; ++d)
    {
        int r = sr + dr4[d], c = sc + dc4[d], step = 1;
        if (r < 0 || r >= R || c < 0 || c >= S) continue;
        while (1) {
            char ch = g[r][c];
            if (ch == 'x') {
                if (step < bestLen || (step == bestLen && dir4[d] < bestDir)) {
                    bestLen = step;
                    bestDir = dir4[d];
                }
                break;
            }
            if (ch == '.' || (r == sr && c == sc)) break;
            int nr = r, nc = c;
            if (ch == 'v') nr++;
            else if (ch == '^') nr--;
            else if (ch == '<') nc--;
            else if (ch == '>') nc++;
            else break;
            r = nr; c = nc; step++;
        }
    }

    if (!bestDir) puts(":(");
    else {
        puts(":)");
        putchar(bestDir);
        putchar('\n');
    }

    for (int i = 0; i < R; ++i) free(g[i]);
    free(g);
    return 0;
}