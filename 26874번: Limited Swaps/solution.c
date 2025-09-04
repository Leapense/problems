#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int a[105], b[105];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    int posA[105], posB[105];
    for (int i = 0; i <= n; i++) {
        posA[i] = -1; posB[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        posA[a[i]] = i; posB[b[i]] = i;
    }

    for (int x = 1; x <= n - 1; x++) {
        int ra = posA[x] < posA[x + 1];
        int rb = posB[x] < posB[x + 1];
        if (ra != rb) {
            printf("-1\n");
            return 0;
        }
    }

    int cur[105];
    for (int i = 0; i < n; i++) cur[i] = a[i];
    for (int i = 0; i <= n; i++) posA[i] = -1;
    for (int i = 0; i < n; i++) posA[cur[i]] = i;

    int ops[20005];
    int k = 0;

    for (int i = 0; i < n; i++) {
        int t = b[i];
        int p = posA[t];
        while (p > i) {
            int lv = cur[p - 1];
            int rv = cur[p];
            int diff = lv - rv;
            if (diff < 0) diff = -diff;
            if (diff < 2) { printf("-1\n"); return 0; }
            if (k >= 20000) { printf("-1\n"); return 0; }
            int tmp = cur[p - 1];
            cur[p - 1] = cur[p];
            cur[p] = tmp;
            posA[cur[p]] = p;
            posA[cur[p - 1]] = p - 1;
            ops[k++] = p;
            p--;
        }
    }

    printf("%d\n", k);
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            if (i) printf(" ");
            printf("%d", ops[i]);
        }
        printf("\n");
    }
    return 0;
}