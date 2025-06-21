#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 500
#define MAX_M 50

char spotty[MAX_N][MAX_M + 1];
char plain[MAX_N][MAX_M + 1];

bool is_valid(int a, int b, int c, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (spotty[i][a] == plain[j][a] && spotty[i][b] == plain[j][b] && spotty[i][c] == plain[j][c]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", spotty[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", plain[i]);
    }

    int count = 0;
    for (int a = 0; a < M; a++) {
        for (int b = a + 1; b < M; b++) {
            for (int c = b + 1; c < M; c++) {
                if (is_valid(a, b, c, N, M)) {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
