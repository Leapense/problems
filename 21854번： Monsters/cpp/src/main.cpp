#include "main.h"
#include <iostream>
#include <vector>
#include <numeric>

int64_t power(int64_t base, int64_t exp)
{
    int64_t res = 1;
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

int64_t calculate_total_sum(const std::vector<int64_t> &k_values)
{
    int64_t total_sum = 0;
    for (int64_t k : k_values)
    {
        if (k < 0)
        {
            continue;
        }

        int64_t distinct_values = power(2, k);
        total_sum = (total_sum + distinct_values) % MOD;
    }

    return total_sum;
}

#ifndef UNIT_TESTS
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int64_t> k_values(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> k_values[i];
    }

    int64_t result = calculate_total_sum(k_values);
    std::cout << result << std::endl;

    return 0;
}
#endif