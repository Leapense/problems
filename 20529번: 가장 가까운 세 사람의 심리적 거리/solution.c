#include <stdio.h>
#include <string.h>

static int encode(const char *s) {
    int v = 0;
    v |= (s[0] == 'I') << 3;
    v |= (s[1] == 'N') << 2;
    v |= (s[2] == 'F') << 1;
    v |= (s[3] == 'P');
    return v;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    int dist[16][16];
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            dist[i][j] = __builtin_popcount(i ^ j);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt[16] = {0};
        char s[5];
        for (int i = 0; i < n; ++i) {
            scanf("%4s", s);
            ++cnt[encode(s)];
        }
        int ans = 12;
        for (int i = 0; i < 16 && ans; ++i) {
            for (int j = i; j < 16 && ans; ++j) {
                for (int k = j; k < 16 && ans; ++k) {
                    if (i == j && j == k) {
                        if (cnt[i] < 3) continue;
                    } else if (i == j) {
                        if (cnt[i] < 2 || cnt[k] < 1) continue;
                    } else if (j == k) {
                        if (cnt[j] < 2 || cnt[i] < 1) continue;
                    } else {
                        if (cnt[i] < 1 || cnt[j] < 1 || cnt[k] < 1) continue;
                    }
                    int d = dist[i][j] + dist[j][k] + dist[i][k];
                    if (d < ans) ans = d;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
