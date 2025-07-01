#include <stdint.h>
#include <stdio.h>

#define MAX_N 20
#define MAX_MASK (1U << MAX_N)

static uint32_t dp[MAX_MASK];
static uint32_t seen[MAX_MASK];
static uint32_t adj[MAX_N];
static int      n;

static uint32_t solve(uint32_t mask) {
    if (mask == 0U || (mask & (mask - 1U)) == 0U) {
        return 0U;
    }
    if (seen[mask]) {
        return dp[mask];
    }
    seen[mask] = 1U;

    int first = __builtin_ctz(mask);
    uint32_t withoutFirst = mask & ~(1U << first);
    uint32_t best = solve(withoutFirst);

    for (int j = first + 1; j < n; ++j) {
        if ((withoutFirst & (1U << j)) && (adj[first] & (1U << j))) {
            uint32_t candidate = 2U + solve(withoutFirst & ~(1U << j));
            if (candidate > best) {
                best = candidate;
            }
        }
    }
    dp[mask] = best;
    return best;
}

int main(void) {
    int m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        adj[u] |= 1U << v;
        adj[v] |= 1U << u;
    }

    uint32_t matched = solve((1U << n) - 1U);
    uint32_t answer  = matched;
    if (matched < (uint32_t) n) {
        ++answer;
    }
    printf("%u\n", answer);
    return 0;
}

