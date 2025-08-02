#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

static const int MAX_P = 250000;
static const int PRIME_CAP = 30000;

static void make_primes(int *primes, int *count) {
    bool *mark = calloc((size_t)MAX_P + 1U, sizeof(bool));
    for (int i = 2; i <= MAX_P; ++i) {
        mark[i] = true;
    }

    for (int i = 2; i * i <= MAX_P; ++i) {
        if (mark[i]) {
            for (int j = i * i; j <= MAX_P; j += i) {
                mark[j] = false;
            }
        }
    }

    int idx = 0;
    for (int i = 2; i <= MAX_P; ++i) {
        if (mark[i]) {
            primes[idx++] = i;
        }
    }

    *count = idx;
    free(mark);
}

static int cmp_int(const void *a, const void *b) {
    int lhs = *(const int *)a;
    int rhs = *(const int *)b;
    return (lhs > rhs) - (lhs < rhs);
}

int main(void) {
    int *primes = malloc(PRIME_CAP * sizeof(int));
    int prime_cnt = 0;
    make_primes(primes, &prime_cnt);

    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = malloc((size_t)n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, (size_t)n, sizeof(int), cmp_int);

        int64_t best = INT64_MAX;

        for (int s = 0; s + n <= prime_cnt; ++s) {
            int64_t cost = 0;
            for (int i = 0; i < n; ++i) {
                cost += llabs((long long)arr[i] - primes[s + i]);
                if (cost >= best) {
                    break;
                }
            }

            if (cost < best) {
                best = cost;
            }
        }

        printf("%" PRId64 "\n", best);
        free(arr);
    }

    free(primes);
    return 0;
}