#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> bundles(N);
    vector<int> internalTrans(N, 0);
    vector<char> first(N), last(N);

    for (int i = 0; i < N; i++)
    {
        cin >> bundles[i];
        first[i] = bundles[i].front();
        last[i] = bundles[i].back();

        for (size_t j = 1; j < bundles[i].size(); ++j)
        {
            if (bundles[i][j] != bundles[i][j - 1])
            {
                internalTrans[i]++;
            }
        }
    }

    vector<vector<int>> cost(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;
            cost[i][j] = (last[i] != first[j]) ? 1 : 0;
        }
    }

    const int INF = numeric_limits<int>::max() / 2;
    vector<vector<int>> dp(1 << N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i)
    {
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        for (int i = 0; i < N; ++i)
        {
            if (!(mask & (1 << i)))
                continue;
            for (int j = 0; j < N; ++j)
            {
                if (mask & (1 << j))
                    continue;
                int nextMask = mask | (1 << j);
                dp[nextMask][j] = min(dp[nextMask][j], dp[mask][i] + cost[i][j]);
            }
        }
    }

    int minBoundaryCost = INF;
    for (int i = 0; i < N; ++i)
    {
        minBoundaryCost = min(minBoundaryCost, dp[(1 << N) - 1][i]);
    }

    int totalInternal = 0;
    for (int i = 0; i < N; ++i)
    {
        totalInternal += internalTrans[i];
    }

    cout << totalInternal + minBoundaryCost << "\n";

    return 0;
}