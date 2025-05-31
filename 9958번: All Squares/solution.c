#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int GRID_CENTER = 1024;
static const int GRID_MIN    = 0;
static const int GRID_MAX    = 2048;

static int countSquares(int s, int cx, int cy, int px, int py)
{
    if (s < 1) return 0;

    int count = 0;
    if ((cx - s) <= px && px <= (cx + s) && (cy - s) <= py && py <= (cy + s)) {
        count = 1;
    }

    int s2 = s / 2;
    if (s2 >= 1) {
        const int dx[4] = {-s, -s, +s, +s};
        const int dy[4] = {-s, +s, -s, +s};

        for (int i = 0; i < 4; ++i) {
            int childCx = cx + dx[i];
            int childCy = cy + dy[i];
            count += countSquares(s2, childCx, childCy, px, py);
        }
    }

    return count;
}

int main()
{
    while (true)
    {
        int k, px, py;
        if (scanf("%d %d %d", &k, &px, &py) != 3) {
            break;
        }

        if (k == 0 && px == 0 && py == 0) {
            break;
        }

        if (k < 1 || k > 512 || px < GRID_MIN || px > GRID_MAX || py < GRID_MIN || py > GRID_MAX) {
            printf("0\n");
            continue;
        }

        int result = countSquares(k, GRID_CENTER, GRID_CENTER, px, py);

        printf("%d\n", result);
    }

    return EXIT_SUCCESS;
}