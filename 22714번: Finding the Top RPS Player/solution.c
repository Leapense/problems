#include <stdio.h>
#include <stdint.h>

static int64_t solve_case(int n, int m) {
    if (m <= 0) return 0;
    if (m == 1) return 1;
    int64_t turns = 0;
    int gsize = m + 1;
    int g[32] = {0};
    int next[32] = {0};
    g[0] = n;

    while (1) {
        if (g[m] > 0) return turns;
        for (int i = 0; i < gsize; ++i) next[i] = 0;
        int add_zero = 0;
        int matches0 = g[0] / 2;
        next[1] += matches0;
        add_zero += matches0 + (g[0] % 2);
        for (int k = 1; k < m; ++k) {
            int matches = g[k] / 2;
            next[k + 1] += matches;
            add_zero += matches;
            if (g[k] % 2) next[k] += 1;
        }
        next[0] += add_zero;
        ++turns;
        for (int i = 0; i < gsize; ++i) g[i] = next[i];
    }
}

int main(void) {
    int n, m;
    int case_no = 1;
    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0) break;
        int64_t ans = solve_case(n, m);
        printf("Case %d: %lld\n", case_no++, (long long)ans);
    }

    return 0;
}