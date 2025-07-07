#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int **a = malloc((size_t)n * sizeof *a);
        for (int i = 0; i < n; ++i) {
            a[i] = malloc((size_t)m * sizeof *a[i]);
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int run = 0;
            for (int j = 0; j < m; ++j) {
                run = a[i][j] == 1 ? run + 1 : 0;
                if (run > maxLen) {
                    maxLen = run;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int run = 0;
            for (int i = 0; i < n; ++i) {
                run = a[i][j] == 1 ? run + 1 : 0;
                if (run > maxLen) {
                    maxLen = run;
                }
            }
        }

        if (maxLen > k) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int out = a[i][j] == 1 ? (i + j) % k + 1 : 0;
                    printf("%d%s", out, j + 1 < m ? " " : "");
                }
                puts("");
            }
        }

        for (int i = 0; i < n; ++i) {
            free(a[i]);
        }
        free(a);
    }
    return 0;
}