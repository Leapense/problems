#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

struct Tree
{
    int H, A;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Tree> trees(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> trees[i].H;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> trees[i].A;
    }

    std::ranges::sort(trees, [](const Tree &a, const Tree &b)
                      { return a.A < b.A; });

    long long total = 0;
    for (int day = 0; day < n; ++day)
    {
        total += trees[day].H + static_cast<long long>(day) * trees[day].A;
    }

    std::cout << total << "\n";

    return 0;
}