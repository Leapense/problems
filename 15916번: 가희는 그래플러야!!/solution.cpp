#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n))
    {
        return 0;
    }

    std::vector<std::int64_t> y(n + 1);
    y[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> y[i];
    }

    std::int64_t k;
    std::cin >> k;

    std::int64_t prev = 0;
    bool meet = false;

    for (int i = 1; i <= n && !meet; ++i)
    {
        std::int64_t curr = y[i] - k * static_cast<std::int64_t>(i);
        if ((curr == 0 && i > 0) || (prev == 0 && i - 1 > 0) || ((prev < 0 && curr > 0) || (prev > 0 && curr < 0))) {
            meet = true;
        }
        prev = curr;
    }

    std::cout << (meet ? 'T' : 'F') << '\n';
    return 0;
}