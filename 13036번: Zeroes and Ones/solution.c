#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int t;
    if (scanf("%d", &t) != 1) {
        return EXIT_FAILURE;
    }

    while (t-- > 0) {
        int n;
        scanf("%d", &n);

        char *s = malloc((size_t)n + 1);
        char *u = malloc((size_t)n + 1);
        if (!s || !u) {
            return EXIT_FAILURE;
        }

        scanf("%s %s", s, u);
        int *d = malloc(sizeof(int) * n);
        if (!d) {
            return EXIT_FAILURE;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            d[i] = (s[i] != u[i]) ? 1 : 0;
            sum += d[i];
        }

        if (sum % 2 != 0) {
            printf("-1\n");
        } else {
            int ops = 0;
            for (int i = 0; i < n - 1; i++) {
                if (d[i] == 1) {
                    d[i] = 0;
                    d[i + 1] ^= 1;
                    ops++;
                }
            }

            printf("%d\n", ops);
        }

        free(s);
        free(u);
        free(d);
    }

    return EXIT_SUCCESS;
}