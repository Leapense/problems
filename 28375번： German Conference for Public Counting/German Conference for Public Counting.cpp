#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

class Solution
{
public:
    string s;
    int L;
    int dp[20][2][2];
    bool vis[20][2][2];
    int curDigit;

    int dfs(int pos, int tight, int started)
    {
        if (pos == L)
            return (started ? 0 : (curDigit == 0 ? 1 : 0));
        if (vis[pos][tight][started])
            return dp[pos][tight][started];
        int limit = (tight ? s[pos] - '0' : 9);
        int best = -1;

        for (int d = 0; d <= limit; d++)
        {
            int nstarted = started || (d != 0);
            int ntight = (tight && (d == limit));
            int add = (nstarted && d == curDigit ? 1 : 0);
            best = max(best, add + dfs(pos + 1, ntight, nstarted));
        }

        vis[pos][tight][started] = true;
        dp[pos][tight][started] = best;
        return best;
    }

    int solveForDigit(int d, ll n)
    {
        curDigit = d;
        int bestDP;

        s = to_string(n);
        L = s.size();
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                {
                    vis[i][j][k] = false;
                }

        bestDP = dfs(0, 1, 0);
        int bestLower = 0;

        for (int len = 1; len < L; len++)
        {
            if (len == 1)
            {
                if (d <= 9)
                    bestLower = max(bestLower, 1);
            }
            else
            {
                if (d == 0)
                    bestLower = max(bestLower, len - 1);
                else
                    bestLower = max(bestLower, len);
            }
        }

        return max(bestDP, bestLower);
    }

    void solve()
    {
        ll n;
        cin >> n;
        int ans = 0;
        for (int d = 0; d < 10; d++)
        {
            ans += solveForDigit(d, n);
        }
        cout << ans << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    sol.solve();

    return 0;
}