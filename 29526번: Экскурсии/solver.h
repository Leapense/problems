#pragma once
#include <vector>
#include <unordered_map>

int bestHoliday(const std::vector<long long> &a, int k)
{
    int n = (int)a.size();
    std::unordered_map<long long, int> cnt;
    int distinct = 0;
    for (int i = 0; i < k; ++i)
        if (cnt[a[i]]++ == 0)
            ++distinct;
    int bestPos = 0, bestVal = distinct;
    for (int r = k; r < n; ++r)
    {
        long long leftVal = a[r - k];
        if (--cnt[leftVal] == 0)
        {
            cnt.erase(leftVal);
            --distinct;
        }
        if (cnt[a[r]]++ == 0)
            ++distinct;
        if (distinct > bestVal)
        {
            bestVal = distinct;
            bestPos = r - k + 1;
        }
    }
    return bestPos + 1;
}