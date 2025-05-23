#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> canPlay(n, vector<bool>(1001, false));

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int note;
            cin >> note;
            canPlay[i][note] = true;
        }
    }

    vector<int> tune(m);
    for (int i = 0; i < m; i++)
    {
        cin >> tune[i];
    }

    vector<vector<int>> coverage(n, vector<int>(m, -1));

    for (int inst = 0; inst < n; inst++)
    {
        for (int pos = 0; pos < m; pos++)
        {
            if (!canPlay[inst][tune[pos]])
            {
                coverage[inst][pos] = -1;
                continue;
            }
            int j = pos;
            while (j < m && canPlay[inst][tune[j]])
                j++;
            coverage[inst][pos] = j - 1;
        }
    }

    const int INF = numeric_limits<int>::max() / 2;
    vector<int> dp(m + 1, INF);
    dp[m] = 0;

    for (int pos = m - 1; pos >= 0; pos--)
    {
        for (int inst = 0; inst < n; inst++)
        {
            if (coverage[inst][pos] == -1)
                continue;

            int nextPos = coverage[inst][pos] + 1;
            int switches = (nextPos == m ? 0 : 1 + dp[nextPos]);
            dp[pos] = min(dp[pos], switches);
        }
    }

    cout << dp[0] << "\n";

    return 0;
}