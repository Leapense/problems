#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    while (n--)
    {
        int x;
        cin >> x;

        vector<int> weights(x);
        for (int &w : weights)
        {
            cin >> w;
        }

        int W;
        cin >> W;

        const int INF = x + 1;
        vector<int> dp(W + 1, INF);
        dp[0] = 0;

        for (int wt : weights)
        {
            if (wt > W)
                continue;
            for (int w = W; w >= wt; --w)
            {
                dp[w] = min(dp[w], dp[w - wt] + 1);
            }
        }

        if (dp[W] <= x)
        {
            cout << dp[W] << "\n";
        }
        else
        {
            cout << "Not possible\n";
        }
    }

    return 0;
}