#include <stdio.h>
#include <stdlib.h>

static void process_line(int *line, int n) {
    int *buffer = malloc(n * sizeof *buffer);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (line[i] != 0) {
            buffer[idx++] = line[i];
        }
    }

    for (int i = 0; i + 1 < idx; i++) {
        if (buffer[i] == buffer[i + 1]) {
            buffer[i] *= 2;
            buffer[i + 1] = 0;
            i++;
        }
    }

    int write = 0;
    for (int i = 0; i < idx; i++) {
        if (buffer[i] != 0) {
            line[write++] = buffer[i];
        }
    }
    while (write < n) {
        line[write++] = 0;
    }

    free(buffer);
}

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) {
        return 1;
    }

    for (int tc = 1; tc <= T; tc++) {
        int N;
        char dir[6];
        scanf("%d %5s", &N, dir);

        int board[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        if (dir[0] == 'l') {
            for (int i = 0; i < N; i++) {
                process_line(board[i], N);
            }
        } else if (dir[0] == 'r') {
            for (int i = 0; i < N; i++) {
                int temp[N];
                for (int j = 0; j < N; j++) {
                    temp[j] = board[i][N - 1 - j];
                }
                process_line(temp, N);
                for (int j = 0; j < N; j++) {
                    board[i][N - 1 - j] = temp[j];
                }
            }
        } else if (dir[0] == 'u') {
            for (int j = 0; j < N; j++) {
                int temp[N];
                for (int i = 0; i < N; i++) {
                    temp[i] = board[i][j];
                }
                process_line(temp, N);
                for (int i = 0; i < N; i++) {
                    board[i][j] = temp[i];
                }
            }
        } else {
            for (int j = 0; j < N; j++) {
                int temp[N];
                for (int i = 0; i < N; i++) {
                    temp[i] = board[N - 1 - i][j];
                }

                process_line(temp, N);
                for (int i = 0; i < N; i++) {
                    board[N - 1 - i][j] = temp[i];
                }
            }
        }

        printf("Case #%d:\n", tc);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", board[i][j]);
                if (j + 1 < N) {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
    }

    return 0;
}