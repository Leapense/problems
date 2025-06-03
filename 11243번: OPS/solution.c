#include <stdio.h>
#include <stdbool.h>

#define MAX_M 1000000

static bool is_prime[MAX_M + 1];
static int prev_prime[MAX_M + 1];

static void build_sieve(void)
{
    for (int i = 0; i <= MAX_M; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for (int p = 2; p * p <= MAX_M; ++p) {
        if (!is_prime[p]) continue;
        for (int multiple = p * p; multiple <= MAX_M; multiple += p) {
            is_prime[multiple] = false;
        }
    }

    int last = -1;
    for (int i = 0; i <= MAX_M; ++i) {
        if (is_prime[i]) {
            last = i;
        }

        prev_prime[i] = last;
    }
}

int main(void)
{
    build_sieve();

    int test_case_count = 0;
    if (scanf("%d", &test_case_count) != 1) {
        return 0;
    }

    while (test_case_count-- > 0) {
        int m = 0;
        scanf("%d", &m);

        printf("%d\n", prev_prime[m - 6]);
    }

    return 0;
}