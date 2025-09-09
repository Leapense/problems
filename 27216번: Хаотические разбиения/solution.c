#include <stdio.h>

static int n;
static int path[100];
static int sz;

static void dfs(int start, int sum) {
    if (sum == n) {
        if (sz > 0) {
            for (int i = 0; i < sz; ++i) {
                if (i) putchar('+');
                printf("%d", path[i]);
            }
            putchar('\n');
        }

        return;
    }

    for (int x = start; x <= n; ++x) {
        if (sum + x > n) break;
        if (sz >= 2) {
            int a = path[sz - 2];
            int b = path[sz - 1];
            if (2 * b == a + x) continue;
        }

        path[sz++] = x;
        dfs(x + 1, sum + x);
        --sz;
    }
}

int main(void)
{
    if (scanf("%d", &n) != 1) return 0;
    sz = 0;
    dfs(1, 0);
    return 0;
}