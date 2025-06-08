#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10
#define MAX_M 10
#define MAX_TESTS 100

static bool isPatternPossible(int n, int m, const int a[MAX_N][MAX_M]);

int main(void)
{
    int t;
    if (scanf("%d", &t) != 1 || t < 1 || t > MAX_TESTS) {
        return 1;
    }

    for (int caseIdx = 1; caseIdx <= t; ++caseIdx) {
        int n, m;
        (void)scanf("%d %d", &n, &m);

        int a[MAX_N][MAX_M];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                (void)scanf("%d", &a[i][j]);
            }
        }
        const bool ok = isPatternPossible(n, m, a);
        printf("Case #%d: %s\n", caseIdx, ok ? "YES" : "NO");
    }

    return 0;
}

static bool isPatternPossible(const int n, const int m, const int a[MAX_N][MAX_M]) {
    int rowMax[MAX_N] = {0};
    int colMax[MAX_M] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > rowMax[i]) { rowMax[i] = a[i][j]; }
            if (a[i][j] > colMax[j]) { colMax[j] = a[i][j]; }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rowMax[i] > a[i][j] && colMax[j] > a[i][j]) {
                return false;
            }
        }
    }

    return true;
}