#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Range
{
    int low, high;
};

Range getRange(char grade, int s, int g, int p, int d, bool isFirstMonth)
{
    Range r;
    if (grade == 'B')
    {
        r.low = 0;
        r.high = s - 1;
    }
    else if (grade == 'S')
    {
        r.low = s;
        r.high = g - 1;
    }
    else if (grade == 'G')
    {
        r.low = g;
        r.high = p - 1;
    }
    else if (grade == 'P')
    {
        r.low = p;
        r.high = d - 1;
    }
    else if (grade == 'D')
    {
        if (isFirstMonth)
        {
            r.low = d;
            r.high = d;
        }
        else
        {
            r.low = d;
            r.high = 2 * d;
        }
    }

    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int s, g, p, d;
    cin >> s >> g >> p >> d;

    string grades;
    cin >> grades;

    vector<vector<int>> dp(N + 1, vector<int>(d + 1, -1));

    Range r = getRange(grades[0], s, g, p, d, true);
    for (int x = 0; x <= d; x++)
    {
        if (x >= r.low && x <= r.high)
        {
            dp[1][x] = x;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        Range range = getRange(grades[i - 1], s, g, p, d, false);
        for (int prev = 0; prev <= d; prev++)
        {
            if (dp[i - 1][prev] == -1)
                continue;
            for (int y = 0; y <= d; y++)
            {
                int sum = prev + y;
                if (sum >= range.low && sum <= range.high)
                {
                    dp[i][y] = max(dp[i][y], dp[i - 1][prev] + y);
                }
            }
        }
    }

    int ans = 0;

    for (int x = 0; x <= d; x++)
    {
        ans = max(ans, dp[N][x]);
    }

    cout << ans << "\n";

    return 0;
}