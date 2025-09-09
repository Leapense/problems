#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned long long mask;
    int cred;
} Cls;

static Cls arr[20];
static int m = 0;
static int K;
static long long ans = 0;

void dfs(int i, unsigned long long used, int sum) {
    if (sum == K) { ++ans; return; }
    if (sum > K || i == m) return;

    dfs(i + 1, used, sum);
    if ((used & arr[i].mask) == 0ULL) {
        dfs(i + 1, used | arr[i].mask, sum + arr[i].cred);
    }
}

int main(void) {
    int n;
    if (scanf("%d %d", &n, &K) != 2) return 0;

    for (int i = 0; i < n; ++i) {
        int w, s, e;
        scanf("%d %d %d", &w, &s, &e);
        if (w == 5) continue;
        unsigned long long msk = 0ULL;
        for (int t = s; t <= e; ++t) {
            int slot = (w - 1) * 10 + (t - 1);
            msk |= (1ULL << slot);
        }

        arr[m].mask = msk;
        arr[m].cred = e - s + 1;
        ++m;
    }

    dfs(0, 0ULL, 0);
    printf("%lld\n", ans);
    return 0;
}