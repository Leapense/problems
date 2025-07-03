#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAXN 15
#define MAXM 100

typedef struct { int to; int topic; } Log;

int n, m;
int taste[MAXN][4];
int pref[MAXN][2];
Log adj[MAXN][MAXM];
int deg[MAXN];

int cand[MAXN][MAXN], cnt[MAXN];
int order[MAXN], placed[MAXN];

int cmp_cnt(const void *a, const void *b) {
    int i = *(const int *)a;
    int j = *(const int *)b;
    return cnt[i] - cnt[j];
}

bool dfs(int idx, int used) {
    if (idx == n) return true;
    int l = order[idx];
    for (int c = 0; c < cnt[l]; ++c) {
        int f = cand[l][c];
        if (used & (1 << f)) continue;
        bool ok = true;
        for (int k = 0; k < deg[l]; ++k) {
            int nb = adj[l][k].to;
            int tp = adj[l][k].topic;
            int g = placed[nb];
            if (g != -1 && taste[f][tp] != taste[g][tp]) { ok = false; break; }
        }
        if (!ok) continue;
        placed[l] = f;
        if (dfs(idx + 1, used | (1 << f))) return true;
        placed[l] = -1;
    }
    return false;
}

int main(void) {
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; ++i)
        for (int t = 0; t < 4; ++t) scanf("%d", &taste[i][t]);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &pref[i][0], &pref[i][1]);
        --pref[i][0]; --pref[i][1];
    }

    memset(deg, 0, sizeof deg);
    for (int i = 0; i < m; ++i) {
        int a, b, t; scanf("%d %d %d", &a, &b, &t);
        --a; --b; --t;
        adj[a][deg[a]++] = (Log){b, t};
        adj[b][deg[b]++] = (Log){a, t};
    }

    memset(cnt, 0, sizeof cnt);
    for (int f = 0; f < n; ++f)
        for (int k = 0; k < 2; ++k) {
            int l = pref[f][k];
            bool seen = false;
            for (int c = 0; c < cnt[l]; ++c) if (cand[l][c] == f) { seen = true; break; }
            if (!seen) cand[l][cnt[l]++] = f;
        }

    for (int l = 0; l < n; ++l) if (cnt[l] == 0) { puts("NO"); return 0; }

    for (int l = 0; l < n; ++l) order[l] = l;
    qsort(order, n, sizeof(int), cmp_cnt);
    for (int l = 0; l < n; ++l) placed[l] = -1;

    if (!dfs(0, 0)) { puts("NO"); return 0; }

    puts("YES");
    for (int l = 0; l < n; ++l) {
        printf("%d", placed[l] + 1);
        if (l + 1 < n) putchar(' ');
    }
    putchar('\n');
    return 0;
}