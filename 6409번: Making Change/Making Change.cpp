#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int coins[6];
        for (int i = 0; i < 6; i++)
        {
            cin >> coins[i];
        }

        if (coins[0] == 0 && coins[1] == 0 && coins[2] == 0 && coins[3] == 0 && coins[4] == 0 && coins[5] == 0)
            break;

        double amount;
        cin >> amount;

        int target = (int)(amount * 100 + 0.5);
        int coinValues[6] = {5, 10, 20, 50, 100, 200};
        int maxSum = 0;

        for (int i = 0; i < 6; i++)
        {
            maxSum += coins[i] * coinValues[i];
        }
        const int INF = numeric_limits<int>::max() / 2;
        vector<int> dp(maxSum + 1, INF);

        dp[0] = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = maxSum; j >= 0; j--)
            {
                if (dp[j] != INF)
                {
                    for (int k = 1; k <= coins[i] && j + k * coinValues[i] <= maxSum; k++)
                    {
                        dp[j + k * coinValues[i]] = min(dp[j + k * coinValues[i]], dp[j] + k);
                    }
                }
            }
        }

        auto changeCoins = [&](int change) -> int
        {
            int cnt = 0;
            int coinSet[6] = {200, 100, 50, 20, 10, 5};
            for (int i = 0; i < 6; i++)
            {
                cnt += change / coinSet[i];
                change %= coinSet[i];
            }

            return cnt;
        };

        int ans = INF;
        for (int s = target; s <= maxSum; s++)
        {
            if (dp[s] != INF)
            {
                ans = min(ans, dp[s] + changeCoins(s - target));
            }
        }

        cout.width(3);
        cout << ans << "\n";
    }

    return 0;
}