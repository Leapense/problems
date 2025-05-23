#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(const std::vector<int> &nums)
{
    std::vector<int> lis;

    for (const auto &num : nums)
    {
        auto pos = std::lower_bound(lis.begin(), lis.end(), num);
        if (pos == lis.end())
            lis.push_back(num);
        else
            *pos = num;
    }

    return lis.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> cards(N);
    for (int &card : cards)
    {
        std::cin >> card;
    }

    std::cout << longestIncreasingSubsequence(cards) << std::endl;

    return 0;
}