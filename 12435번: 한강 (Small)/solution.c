#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum { MAX_N = 1000000, MAX_CNT = 240 };  /* empirically safe upper-bound */

/* Global static arrays – zero-initialised */
static uint16_t cnt_div[MAX_N + 1];
static uint32_t min_div[MAX_N + 1];

/* Each entry stores address and youngest divisor */
typedef struct { uint32_t addr; uint32_t youngest; } Pair;

/* Buckets for equal cnt_div */
static Pair *bucket[MAX_CNT + 1];
static uint32_t bucket_size[MAX_CNT + 1];

static void precompute(void)
{
    /* Modified sieve */
    for (uint32_t d = 2; d * 2 <= MAX_N; ++d) {
        for (uint32_t m = d << 1U; m <= MAX_N; m += d) {
            ++cnt_div[m];
            if (min_div[m] == 0U) { min_div[m] = d; }
        }
    }

    /* First pass – count bucket sizes */
    for (uint32_t x = 2; x <= MAX_N; ++x) {
        if (cnt_div[x] > MAX_CNT) { /* realistically never happens */ continue; }
        ++bucket_size[cnt_div[x]];
    }

    /* Allocate buckets */
    for (uint32_t c = 0; c <= MAX_CNT; ++c) {
        if (bucket_size[c] == 0U) { continue; }
        bucket[c] = malloc(bucket_size[c] * sizeof(Pair));
        bucket_size[c] = 0U; /* reuse as cursor */
    }

    /* Second pass – fill buckets in address order */
    for (uint32_t x = 2; x <= MAX_N; ++x) {
        uint16_t c = cnt_div[x];
        Pair *dst   = bucket[c] + bucket_size[c]++;
        dst->addr   = x;
        dst->youngest = min_div[x]; /* 0 if none */
    }
}

static uint32_t answer(uint32_t N, uint32_t M)
{
    uint16_t signature = cnt_div[N];
    if (signature == 0U) { return 0U; } /* N is prime – no younger sisters receive gifts */

    const Pair *list   = bucket[signature];
    uint32_t     sz    = bucket_size[signature];
    /* Upper-bound search for first addr ≥ N */
    uint32_t lo = 0U, hi = sz;
    while (lo < hi) {
        uint32_t mid = (lo + hi) / 2U;
        if (list[mid].addr < N) { lo = mid + 1U; } else { hi = mid; }
    }
    uint32_t idx_end = lo;          /* elements [0, idx_end) are < N */

    uint32_t count = 0U;
    for (uint32_t i = 0U; i < idx_end; ++i) {
        if (list[i].youngest >= M) { ++count; }
    }
    return count;
}

int main(void)
{
    precompute();

    uint32_t T;
    if (scanf("%" SCNu32, &T) != 1U) { return EXIT_FAILURE; }
    for (uint32_t tc = 1U; tc <= T; ++tc) {
        uint32_t N, M;
        (void)scanf("%" SCNu32 " %" SCNu32, &N, &M);
        uint32_t gifts = answer(N, M);
        printf("Case #%" PRIu32 ": %" PRIu32 "\n", tc, gifts);
    }
    return EXIT_SUCCESS;
}