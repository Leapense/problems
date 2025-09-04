#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

static int n;
static int64_t target;
static int64_t coeff[11];
static int ans[11];
static bool used[11];

static void build_binom(void) {
    int64_t c[11][11];
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= n - 1; ++i) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    for (int i = 0; i < n; ++i) coeff[i] = c[n - 1][i];
}

static int avail_nums[11];
static int avail_cnt;

static void refresh_avail(void) {
    avail_cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (!used[v]) {
            avail_nums[avail_cnt++] = v;
        }
    }
}

static int64_t rem_coeff[11];
static int rcnt;

static void build_rem_coeff(int idx) {
    rcnt = 0;
    for (int i = idx + 1; i < n; ++i) rem_coeff[rcnt++] = coeff[i];
    for (int i = 0; i < rcnt - 1; ++i) {
        for (int j = i + 1; j < rcnt; ++j) {
            if (rem_coeff[i] < rem_coeff[j]) {
                int64_t t = rem_coeff[i];
                rem_coeff[i] = rem_coeff[j];
                rem_coeff[j] = t;
            }
        }
    }
}

static void sort_int_asc(int *a, int m) {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

static void sort_int_desc(int *a, int m) {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

static bool feasible_range(int idx, int64_t s) {
    build_rem_coeff(idx);
    refresh_avail();
    int aasc[11], adesc[11];
    for (int i = 0; i < avail_cnt; ++i) {
        aasc[i] = avail_nums[i];
        adesc[i] = avail_nums[i];
    }

    sort_int_asc(aasc, avail_cnt);
    sort_int_desc(adesc, avail_cnt);
    int64_t minAdd = 0, maxAdd = 0;
    for (int i = 0; i < rcnt; ++i) {
        minAdd += (int64_t)aasc[i] * rem_coeff[i];
        maxAdd += (int64_t)adesc[i] * rem_coeff[i];
    }

    return s + minAdd <= target && target <= s + maxAdd;
}

static bool dfs(int idx, int64_t s) {
    if (idx == n) return s == target;
    for (int v = 1; v <= n; ++v) {
        if (used[v]) continue;
        int64_t ns = s + (int64_t)v * coeff[idx];
        used[v] = true;
        if (feasible_range(idx, ns)) {
            ans[idx] = v;
            if (dfs(idx + 1, ns)) return true;
        }
        used[v] = false;
    }
    return false;
}

int main(void) {
    if (scanf("%d %lld", &n, &target) != 2) return 0;
    build_binom();
    memset(used, 0, sizeof(used));
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}