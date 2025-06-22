#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>

enum { MATCH_COUNT = 20, STEP = 50, MAX_DELTA = MATCH_COUNT * STEP };
enum { STATE_SIZE = MAX_DELTA * 2 / STEP + 1 };
enum Tier { BRONZE, SILVER, GOLD, PLATINUM, DIAMOND, TIER_COUNT };

static void simulate(long double wProb, long double lProb, long double dProb, long double out[TIER_COUNT])
{
    long double dp[2][STATE_SIZE] = { 0.0L };
    int cur = 0;
    int offset = MAX_DELTA / STEP;

    dp[cur][offset] = 1.0L;

    for (int i = 0; i < MATCH_COUNT; ++i)
    {
        int nxt = cur ^ 1;
        for (int j = 0; j < STATE_SIZE; ++j)
        {
            dp[nxt][j] = 0.0L;
        }
        for (int j = 0; j < STATE_SIZE; ++j)
        {
            long double prob = dp[cur][j];
            if (prob <= 0.0L) continue;
            dp[nxt][j + 1] += prob * wProb;
            dp[nxt][j] += prob * dProb;
            dp[nxt][j - 1] += prob * lProb;
        }

        cur = nxt;
    }

    for (int j = 0; j < STATE_SIZE; ++j) {
        long double prob = dp[cur][j];
        if (prob <= 0.0L) continue;

        int delta = (j - offset) * STEP;
        int finalScore = 2000 + delta;

        enum Tier tier = DIAMOND;
        if (finalScore < 1500) {
            tier = BRONZE;
        } else if (finalScore < 2000) {
            tier = SILVER;
        } else if (finalScore < 2500) {
            tier = GOLD;
        } else if (finalScore < 3000) {
            tier = PLATINUM;
        }

        out[tier] += prob;
    }
}

int main(void)
{
    long double w, l, d;
    if (scanf("%Lf %Lf %Lf", &w, &l, &d) != 3) {
        return EXIT_FAILURE;
    }

    long double result[TIER_COUNT] = {0.0L};
    simulate(w, l, d, result);

    for (int i = 0; i < TIER_COUNT; ++i) {
        printf("%.8Lf\n", result[i]);
    }

    return EXIT_SUCCESS;
}