#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    long long **p = malloc((n + 1) * sizeof(long long *));
    if (!p) return 0;
    for (int i = 0; i <= n; ++i)
    {
        p[i] = calloc(m + 1, sizeof(long long));
        if (!p[i]) return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int v;
            scanf("%d", &v);
            p[i][j] = v + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    int k;
    scanf("%d", &k);
    while (k--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        long long ans = p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
        printf("%lld\n", ans);
    }

    for (int i = 0; i <= n; ++i)
    {
        free(p[i]);
    }

    free(p);
    return 0;
}