#include <bits/stdc++.h>
using namespace std;

const int hmax = 100, wmax = 100;
char Move[2 * hmax * wmax];
char Maze[2 * hmax - 3][wmax + 1];

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

int main()
{
    int runs, run, n, d, i, j, k, imin, imax, jmax;
    scanf("%d", &runs);
    printf("%d\n", runs);

    for (run = 0; run < runs; run++) {
        scanf("%s", Move);
        n = strlen(Move);
        memset(Maze, '#', sizeof(Maze));
        i = imin = imax = hmax - 2;
        j = jmax = 0;
        d = 0;

        for (k = 0; k < n; k++) {
            Maze[i][j] = '.';
            switch (Move[k]) {
                case 'R': d++; break;
                case 'B': d+=2; break;
                case 'L': d+=3; break;
            }
            d %= 4;

            i += di[d];
            j += dj[d];

            imin = min(imin, i);
            imax = max(imax, i);
            jmax = max(jmax, j);
        }
        
        printf("%d %d\n", imax - imin + 3, jmax + 2);
        for (i = imin - 1; i <= imax + 1; i++) {
            Maze[i][jmax + 2] = '\0';
            printf("%s\n", Maze[i]);
        }
    }

    return 0;
}