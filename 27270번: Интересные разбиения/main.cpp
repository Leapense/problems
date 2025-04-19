#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

void solve(int remaining_sum, int min_allowed_value, std::vector<int> &current_partition, int original_n)
{
    if (remaining_sum == 0)
    {
        std::cout << original_n << "=";
        for (size_t i = 0; i < current_partition.size(); ++i)
        {
            std::cout << current_partition[i] << (i == current_partition.size() - 1 ? "" : "+");
        }
        std::cout << std::endl;
        return;
    }

    for (int v = min_allowed_value; v <= remaining_sum; ++v)
    {
        current_partition.push_back(v);
        solve(remaining_sum - v, v + 2, current_partition, original_n);
        current_partition.pop_back();
    }
}

#ifndef UNIT_TEST
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> current_partition;
    solve(n, 1, current_partition, n);
    return 0;
}
#endif