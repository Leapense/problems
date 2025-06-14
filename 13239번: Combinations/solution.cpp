#include <iostream>
#include <vector>

static constexpr int MOD = 1'000'000'007;
static constexpr int MAX_N = 1000;

long long mod_pow(long long x, long long e) {
    long long r = 1;
    x %= MOD;
    while (e > 0) {
        if (e & 1) {
            r = (r * x) % MOD;
        }
        x = (x * x) % MOD;
        e >>= 1;
    }

    return r;
}

int main()
{
    std::vector<long long> fact(MAX_N + 1, 1), inv_fact(MAX_N + 1, 1);
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[MAX_N] = mod_pow(fact[MAX_N], MOD - 2);
    for (int i = MAX_N; i > 0; --i) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }

    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        if (k < 0 || k > n) {
            std::cout << 0 << "\n";
        } else {
            long long result = fact[n];
            result = result * inv_fact[k] % MOD;
            result = result * inv_fact[n - k] % MOD;
            std::cout << result << "\n";
        }
    }

    return 0;
}