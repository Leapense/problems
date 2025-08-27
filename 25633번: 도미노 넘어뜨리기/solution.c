#include <stdio.h>
#include <stdlib.h>

static int max_domino_chain_length(int n, const long long* weights) {
    if (n <= 0) return 0;
    long long* best = (long long*)malloc((n + 2) * sizeof(long long));
    long long* nextForI = (long long*)malloc((n + 2) * sizeof(long long));
    if (!best || !nextForI) {
        free(best);
        free(nextForI);
        return 0;
    }

    for (int i = 0; i <= n + 1; ++i) best[i] = -1;
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= n + 1; ++k) nextForI[k] = -1;
        for (int len = 1; len <= i; ++len) {
            if (best[len] >= weights[i]) {
                long long candidateSum = best[len] + weights[i];
                if (candidateSum > nextForI[len + 1]) nextForI[len + 1] = candidateSum;
                if (len + 1 > maxLength) maxLength = len + 1;
            }
        }
        if (weights[i] > nextForI[1]) {
            nextForI[1] = weights[i];
            if (maxLength < 1) maxLength = 1;
        }
        for (int len = 1; len <= n; ++len) {
            if (nextForI[len] > best[len]) best[len] = nextForI[len];
        }
    }

    free(best);
    free(nextForI);
    return maxLength;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long* a = (long long*)malloc(n * sizeof(long long));
    if (!a) return 0;
    for (int i = 0; i < n; ++i) {
        long long v;
        if (scanf("%lld", &v) != 1) {
            free(a);
            return 0;
        }
        a[i] = v;
    }

    int result = max_domino_chain_length(n, a);
    printf("%d\n", result);
    free(a);
    return 0;
}