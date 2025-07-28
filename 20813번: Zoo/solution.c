#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

static void buildAllowed(bool allow[10][10], int k, int m) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            allow[i][j] = i != j;
        }
    }
    for (int g = 0; g < m; ++g) {
        char line[16];
        scanf("%15s", line);
        int len = (int)strlen(line);
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int a = line[i] - 'A';
                int b = line[j] - 'A';
                allow[a][b] = false;
                allow[b][a] = false;
            }
        }
    }
}

int main(void) {
    int n, k, m;
    if (scanf("%d %d %d", &n, &k, &m) != 3) {
        return 0;
    }
    bool allow[10][10];
    buildAllowed(allow, k, m);
    int32_t prev[10] = {0};
    int32_t curr[10] = {0};
    for (int s = 0; s < k; ++s) {
        prev[s] = 1;
    }
    for (int pos = 1; pos < n; ++pos) {
        memset(curr, 0, sizeof(curr));
        for (int pr = 0; pr < k; ++pr) {
            if (prev[pr] == 0) {
                continue;
            }
            for (int cu = 0; cu < k; ++cu) {
                if (allow[pr][cu]) {
                    curr[cu] += prev[pr];
                }
            }
        }
        memcpy(prev, curr, sizeof(prev));
    }
    int32_t total = 0;
    for (int s = 0; s < k; ++s) {
        total += prev[s];
    }
    printf("%d\n", total);
    return 0;
}