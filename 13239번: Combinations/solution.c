#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007
#define MAX_N 1000

static int64_t fact[MAX_N + 1];
static int64_t inv_fact[MAX_N + 1];

static int64_t mod_pow(int64_t base, int64_t exp) {
    int64_t result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }

    return result;
}

static void init_factorials(void) {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAX_N] = mod_pow(fact[MAX_N], MOD - 2);
    for (int i = MAX_N; i > 0; --i) {
        inv_fact[i - 1] = (inv_fact[i] * i) % MOD;
    }
}

static int64_t binom(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

int main(void) {
    init_factorials();
    int t = 0;
    if (scanf("%d", &t) != 1) {
        return 1;
    }

    for (int i = 0; i < t; ++i) {
        int n = 0, k = 0;
        if (scanf("%d %d", &n, &k) != 2) {
            return 1;
        }

        printf("%lld\n", binom(n, k));
    }

    return 0;
}