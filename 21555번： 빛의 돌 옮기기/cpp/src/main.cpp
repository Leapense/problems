#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int64_t solve(int n, int64_t k, const std::vector<int64_t> &a, const std::vector<int64_t> &b)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return std::min(a[0], b[0]);

    int64_t prev_drag_cost = a[0];
    int64_t prev_carry_cost = b[0];

    for (int i = 1; i < n; ++i)
    {
        int64_t current_drag_cost = std::min(prev_drag_cost + a[i], prev_carry_cost + k + a[i]);
        int64_t current_carry_cost = std::min(prev_carry_cost + b[i], prev_drag_cost + k + b[i]);

        prev_drag_cost = current_drag_cost;
        prev_carry_cost = current_carry_cost;
    }

    return std::min(prev_carry_cost, prev_drag_cost);
}

#ifndef UNIT_TESTS
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int64_t k;

    std::cin >> n >> k;

    std::vector<int64_t> a(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    std::vector<int64_t> b(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> b[i];
    }

    std::cout << solve(n, k, a, b) << std::endl;
    return 0;
}
#endif