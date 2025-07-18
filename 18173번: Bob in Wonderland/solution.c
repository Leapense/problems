#include <stdio.h>
#include <stdlib.h>

#define MAXN 300005

int deg[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) deg[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        deg[v]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) ans += deg[i] - 2;
    }

    printf("%lld\n", ans);
    return 0;
}