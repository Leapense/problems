#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int Q = 0;
    if (scanf("%d", &Q) != 1) 
    {
        return 0;
    }
    static int prevDP[400];
    static int currDP[400];

    for (int queryIndex = 0; queryIndex < Q; ++queryIndex) {
        int rows = 0, cols = 0, steps = 0, moduloP = 0;
        int scanned = scanf("%d %d %d %d", &rows, &cols, &steps, &moduloP);

        if (scanned != 4) {
            break;
        }

        if (rows < 1 || rows > 20 || cols < 1 || cols > 20 || steps < 1 || steps > 1000 || moduloP < 1 || moduloP > 1000000) {
            printf("0\n");
            continue;
        }

        const int N = rows * cols;

        if (steps == 1) {
            int result = N % moduloP;
            printf("%d\n", result);
            continue;
        }

        for (int i = 0; i < N; ++i) {
            prevDP[i] = 1;
        }

        const int dr[5] = {-1, +1, 0, 0, 0};
        const int dc[5] = {0, 0, -1, +1, 0};

        for (int stepIndex = 2; stepIndex <= steps; ++stepIndex) {
            for (int idx = 0; idx < N; ++idx) {
                currDP[idx] = 0;
            }

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    int targetIdx = r * cols + c;
                    int accumulator = 0;

                    for (int dir = 0; dir < 5; ++dir) {
                        int nr = r + dr[dir];
                        int nc = c + dc[dir];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                            int fromIdx = nr * cols + nc;
                            accumulator += prevDP[fromIdx];
                            if (accumulator >= moduloP) {
                                accumulator %= moduloP;
                            }
                        }
                    }

                    currDP[targetIdx] = (accumulator % moduloP);
                }
            }
            for (int idx = 0; idx < N; ++idx) {
                prevDP[idx] = currDP[idx];
            }
        }

        int64_t sumWays = 0;
        for (int i = 0; i < N; ++i) {
            sumWays += prevDP[i];
            if (sumWays >= INT64_C(1000000000000)) {
                sumWays %= moduloP;
            }
        }

        int result = (int)(sumWays % moduloP);
        printf("%d\n", result);
    }

    return 0;
}