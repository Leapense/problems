#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> bricks(n);
        int totalThickness = 0;
        for (int i = 0; i < n; i++)
        {
            int t, w;
            cin >> t >> w;
            bricks[i] = {t, w};
            totalThickness += t;
        }
        vector<int> dp(totalThickness + 1, -1);
        dp[0] = 0;
        for (auto [t, w] : bricks)
        {
            int cost = t + w;
            for (int j = totalThickness; j >= cost; j--)
            {
                if (dp[j - cost] != -1)
                {
                    dp[j] = max(dp[j], dp[j - cost] + t);
                }
            }
        }
        int best = 0;
        for (int j = 0; j <= totalThickness; j++)
        {
            best = max(best, dp[j]);
        }
        cout << totalThickness - best << "\n";
    }
    return 0;
}
