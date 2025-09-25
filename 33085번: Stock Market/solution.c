#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int N;
    long long P0, X;
    if (scanf("%d %lld %lld", &N, &P0, &X) != 3) return 0;

    long long *D = (long long *)malloc(sizeof(long long) * (size_t)N);
    if (!D) return 0;
    long long S = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &D[i]);
        S += D[i];
    }
    long long Sneg = -S;
    long long pref = 0;
    long long ans = LLONG_MAX;

    for (int j = 0; j < N; ++j) {
        long long Bj = P0 + pref;
        if (Bj >= X) {
            long long r = (Bj - X) % Sneg;
            long long cand = X + r;
            if (cand < ans) ans = cand;
        }

        pref += D[j];
    }

    if (ans == LLONG_MAX) printf("-1\n");
    else printf("%lld\n", ans);

    free(D);
    return 0;
}