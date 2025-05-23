#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;
const int INF = -1000000000;

int main(void)
{
    FASTIO;
    vector<bool> emma(1000000, false), marcos(1000000, false);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        emma[d] = true;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        marcos[d] = true;
    }

    array<int, 3> dp = {0, INF, INF};

    for (int d = 0; d < 1000000; d++)
    {
        bool e = emma[d], m = marcos[d];
        int type = -1;
        if (e && m)
            type = 0;
        else if (e && !m)
            type = 1;
        else if (!e && m)
            type = 2;
        if (type == -1)
            continue;
        array<int, 3> ndp = dp;
        if (type == 0)
        {
            int best = max({dp[0], dp[1], dp[2]});
            ndp[0] = max(ndp[0], best + 1);
        }
        else if (type == 1)
        {
            int best = max(dp[0], dp[2]);
            ndp[1] = max(ndp[1], best + 1);
        }
        else if (type == 2)
        {
            int best = max(dp[0], dp[1]);
            ndp[2] = max(ndp[2], best + 1);
        }

        dp = ndp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";

    return 0;
}