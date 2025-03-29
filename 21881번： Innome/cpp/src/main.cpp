#include <iostream>
#include "main.h"

using namespace std;

bool canOpenTabs(long long T, long long k, long long m)
{
    long long x = T / k;
    long long r = T % k;

    __int128 cost1 = ((__int128)x * (x + 1));
    __int128 cost2 = ((__int128)(x + 1) * (x + 2));
    __int128 totalCost = (((__int128)(k - r) * cost1) + ((__int128)r * cost2)) / 2;

    return totalCost <= m;
}

long long computeMaxTabs(long long m, long long k)
{
    long long low = 0, high = 100000000000000LL;
    long long ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (canOpenTabs(mid, k, m))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

#ifndef UNIT_TESTS
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long m, k;
        cin >> m >> k;
        cout << computeMaxTabs(m, k) << "\n";
    }

    return 0;
}
#endif