#include <iostream>
#include <vector>

constexpr long long MOD = 1'000'000'007LL;

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % MOD;
        }

        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long total_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        long long k;
        std::cin >> k;
        long long distinct_values = power(2, k);
        total_sum = (total_sum + distinct_values) % MOD;
    }

    std::cout << total_sum << std::endl;
    return 0;
}