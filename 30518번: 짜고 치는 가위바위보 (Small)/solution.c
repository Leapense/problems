#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MOD 1000000007LL
enum { R=0, P=1, S=2, NONE=3 };
enum { DRAW=0, LWIN=1, LLOSE=2, START=3 };

int n, L0;
int a[21];
int beats_[3] = { S, R, P };
int outcome_(int L, int sm) {
    if (L == sm) return DRAW;
    return (beats_[L] == sm) ? LWIN : LLOSE;
}

int64_t memo[21][4][4];
int vis[21][4][4];

int64_t dfs(int pos, int last, int prev) {
    if (pos == n) {
        return (last != NONE) ? 1 : 0;
    }
    if (vis[pos][last][prev]) return memo[pos][last][prev];
    vis[pos][last][prev] = 1;

    int64_t res = 0;

    res += dfs(pos + 1, last, prev);
    if (res >= MOD) res -= MOD;

    int sm = a[pos];
    int L = (last == NONE ? L0 : last);
    int curRes = outcome_(L, sm);
    if (!(prev == LWIN && curRes == DRAW)) {
        res += dfs(pos + 1, sm, curRes);
        if (res >= MOD) res -= MOD;
    }

    memo[pos][last][prev] = res;
    return res;
}

int mvId(char c) { return c == 'R' ? R : c == 'P' ? P : S; }
int main(void) {
    char L0s[4], Sstr[32];
    if (scanf("%3s", L0s) != 1) return 0;
    if (scanf("%31s", Sstr) != 1) return 0;
    L0 = mvId(L0s[0]);
    n = (int)strlen(Sstr);
    for (int i = 0; i < n; i++) a[i] = mvId(Sstr[i]);

    memset(vis, 0, sizeof(vis));
    int64_t ans = dfs(0, NONE, START);
    printf("%lld\n", (long long)ans);
    return 0;
}