#include "main.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ios>

long long countPairsWithXorSum(const std::vector<unsigned int> &v, unsigned int x)
{
    std::unordered_map<unsigned int, int> freq;
    long long count = 0;
    int n = v.size();

    for (int i = 0; i < n; ++i)
    {
        unsigned int current_val = v[i];
        unsigned int target = x ^ current_val;

        auto it = freq.find(target);
        if (it != freq.end())
        {
            count += it->second;
        }

        freq[current_val]++;
    }

    return count;
}

#ifndef UNIT_TESTS
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--)
    {
        int n;
        unsigned int x;
        std::cin >> n >> x;

        std::vector<unsigned int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }

        long long result = countPairsWithXorSum(v, x);
        std::cout << result << "\n";
    }

    return 0;
}
#endif