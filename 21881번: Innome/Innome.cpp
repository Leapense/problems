#include <iostream>
using namespace std;

using int128 = __int128;

bool canOpenTabs(long long T, long long k, long long m)
{
    long long x = T / k;
    long long r = T % k;

    int128 cost1 = (int128)x * (x + 1);
    int128 cost2 = (int128)(x + 1) * (x + 2);

    int128 totalCost = ((int128)(k - r) * cost1 + (int128)r * cost2) / 2;

    return totalCost <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long m, k;
        cin >> m >> k;

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

        cout << ans << "\n";
    }

    return 0;
}