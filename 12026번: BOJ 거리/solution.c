#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static const long long INF = (long long)4e18;

static char next_char(char c) {
    if (c == 'B') {
        return 'O';
    }
    if (c == 'O') {
        return 'J';
    }

    return 'B';
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    char blocks[1001];
    if (scanf("%s", blocks) != 1) {
        return 0;
    }

    long long *dp = (long long *)malloc(sizeof(long long) * N);
    if (dp == NULL) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        if (dp[i] == INF) {
            continue;
        }
        char required = next_char(blocks[i]);
        for (int j = i + 1; j < N; j++) {
            if (blocks[j] != required) {
                continue;
            }

            long long distance = (long long)(j - i);
            long long cost = distance * distance;
            long long candidate = dp[i] + cost;
            if (candidate < dp[j]) {
                dp[j] = candidate;
            }
        }
    }

    if (dp[N - 1] == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", dp[N-1]);
    }

    free(dp);
    return 0;
}