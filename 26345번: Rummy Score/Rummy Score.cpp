#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> validGroups;
    vector<int> groupSum(1 << 7, 0);

    int tmp[7];
    for (int mask = 0; mask < (1 << 7); mask++)
    {
        int cnt = __builtin_popcount(mask);
        if (cnt < 3)
            continue;

        vector<int> vs;
        for (int i = 0; i < 7; i++)
        {
            if (mask & (1 << i))
                vs.push_back(tmp[i]);
        }

        validGroups.push_back(mask);
    }

    int n;
    cin >> n;

    while (n--)
    {
        vector<int> cards(7);
        for (int i = 0; i < 7; i++)
        {
            cin >> cards[i];
        }

        ostringstream oss;
        for (int i = 0; i < 7; i++)
        {
            if (i)
                oss << ' ';
            oss << cards[i];
        }

        vector<int> realGroups;
        vector<int> realGroupSum;
        for (int mask : validGroups)
        {
            vector<int> vs;
            for (int i = 0; i < 7; i++)
            {
                if (mask & (1 << i))
                    vs.push_back(cards[i]);
            }

            bool same = all_of(vs.begin(), vs.end(), [&](int x)
                               { return x == vs[0]; });
            bool seq = false;

            if (!same)
            {
                sort(vs.begin(), vs.end());
                seq = true;
                for (int i = 1; i < (int)vs.size(); i++)
                {
                    if (vs[i] != vs[i - 1] + 1)
                    {
                        seq = false;
                        break;
                    }
                }
            }

            if (same || seq)
            {
                realGroups.push_back(mask);
                int sum = 0;
                for (int x : vs)
                    sum += x;
                realGroupSum.push_back(sum);
            }
        }

        static int dp[1 << 7];
        fill(dp, dp + (1 << 7), -1);
        dp[0] = 0;

        int best = 0;
        for (int mask = 0; mask < (1 << 7); mask++)
        {
            if (dp[mask] < 0)
                continue;
            best = max(best, dp[mask]);
            for (int i = 0; i < (int)realGroups.size(); i++)
            {
                int g = realGroups[i];
                if ((mask & g) == 0)
                {
                    int nm = mask | g;
                    dp[nm] = max(dp[nm], dp[mask] + realGroupSum[i]);
                }
            }
        }

        int total = accumulate(cards.begin(), cards.end(), 0);
        int lost = total - best;

        cout << "Rummy Hand: " << oss.str() << "\n";
        cout << lost << "\n\n";
    }

    return 0;
}