#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gcd_int(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int H, W;
    if (scanf("%d %d", &H, &W) != 2) return 0;
    char **G = (char **)malloc(sizeof(char*) * H);
    for (int r = 0; r < H; ++r) {
        G[r] = (char *)malloc((size_t)W + 2);
        scanf("%s", G[r]);
    }

    int i_gcd = 0;
    for (int r = 0; r < H; ) {
        int s = r + 1;
        while (s < H && strcmp(G[s], G[r]) == 0) ++s;
        int run = s - r;
        i_gcd = i_gcd == 0 ? run : gcd_int(i_gcd, run);
        r = s;
    }

    int j_gcd = 0;
    for (int c = 0; c < W; ) {
        int s = c + 1;
        int equal = 1;
        while (s < W) {
            equal = 1;
            for (int r = 0; r < H; ++r) {
                if (G[r][s] != G[r][c]) { equal = 0; break; }
            }

            if (!equal) break;
            ++s;
        }

        int run = s - c;
        j_gcd = j_gcd == 0 ? run : gcd_int(j_gcd, run);
        c = s;
    }

    int n = H / i_gcd, m = W / j_gcd;
    printf("%d %d\n", n, m);
    for (int r = 0; r < H; r += i_gcd) {
        for (int c = 0; c < W; c += j_gcd) {
            putchar(G[r][c]);
        }

        putchar('\n');
    }

    for (int r = 0; r < H; ++r) free(G[r]);
    free(G);
    return 0;
}