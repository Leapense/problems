#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool has_axis(const int *v, int n) {
    if ((n & 1) == 0) {
        int h = n / 2;
        for (int c = 0; c < h; ++c) {
            bool ok = true;
            for (int d = 1; d < h && ok; ++d) {
                if (v[(c + d) % n] != v[(c - d + n) % n]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }

        for (int c = 0; c < h; ++c) {
            bool ok = true;
            for (int d = 0; d < h && ok; ++d) {
                if (v[(c - d + n) % n] != v[(c + 1 + d) % n]) {
                    ok = false;
                }
            }

            if (ok) {
                return true;
            }
        }
    } else {
        int h = n / 2;
        for (int c = 0; c < n; ++c) {
            bool ok = true;
            for (int d = 1; d <= h && ok; ++d) {
                if (v[(c + d) % n] != v[(c - d + n) % n]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
    }

    return false;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n <= 5) {
        printf("-1\n");
        return 0;
    }

    int *beads = malloc((size_t)n * sizeof(int));
    int base[6] = {0, 0, 1, 0, 1, 1};
    for (int i = 0; i < n; ++i) {
        beads[i] = base[i % 6];
    }

    if (has_axis(beads, n)) {
        uint32_t seed = 1u;
        while (true)
        {
            uint32_t x = seed++;
            for (int i = 0; i < n; ++i) {
                x = x * 1103515245u + 12345u;
                beads[i] = (int)((x >> 31) & 1u);
            }
            if (!has_axis(beads, n)) {
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", beads[i]);
    }

    putchar('\n');
    free(beads);
    return 0;
}