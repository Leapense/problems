#include <iostream>

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1'000'000'009;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 0 << "\n";
        return 0;
    }

    constexpr long long MOD = 1'000'000'009;
    long long result = power(3, n - 2);
    result = (2 * result) % MOD;
    std::cout << result << "\n";

    return 0;
}