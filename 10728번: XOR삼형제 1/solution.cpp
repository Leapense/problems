#include <iostream>
#include <vector>
#include <algorithm>

static constexpr int POW2_LIST[] = {1, 2, 4, 8, 16, 32, 64};
static constexpr int POW2_COUNT = sizeof(POW2_LIST) / sizeof(POW2_LIST[0]);

static inline int find_highest_power_index(int n) noexcept
{
    int left = 0;
    int right = POW2_COUNT - 1;
    int bestIndex = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (POW2_LIST[mid] <= n) {
            bestIndex = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bestIndex;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testCaseCount = 0;
    if (!(std::cin >> testCaseCount)) {
        return 0;
    }

    for (int tc = 0; tc < testCaseCount; ++tc) {
        int n = 0;
        if (!(std::cin >> n)) {
            return 0;
        }

        if (n == 1) {
            std::cout << "1\n1\n";
            continue;
        }

        if (n == 2) {
            std::cout << "2\n1 2\n";
            continue;
        }

        int idxBig = find_highest_power_index(n);
        int idxSmall = idxBig - 1;

        int bitBig = POW2_LIST[idxBig];
        int bitSmall = POW2_LIST[idxSmall];

        int forbiddenValue = (bitBig | bitSmall);

        int maxAllowed = std::min(n, forbiddenValue - 1);
        int minAllowed = bitSmall;

        int resultLength = maxAllowed - minAllowed + 1;
        if (resultLength < 0) {
            resultLength = 0;
        }

        std::cout << resultLength << "\n";

        if (resultLength > 0)
        {
            for (int val = minAllowed; val <= maxAllowed; ++val)
            {
                if (val == maxAllowed) {
                    std::cout << val << "\n";
                } else {
                    std::cout << val << " ";
                }
            }
        }
        else
        {
            std::cout << "\n";
        }
    }
    return 0;
}