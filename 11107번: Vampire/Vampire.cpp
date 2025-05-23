#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        vector<vector<double>> dp(x + 1, vector<double>(y + 1, 0.0));
        for (int d = 0; d <= x; d++)
        {
            dp[d][0] = 1.0;
        }
        for (int r = 1; r <= y; r++)
        {
            dp[0][r] = 0.0;
        }
        for (int d = 1; d <= x; d++)
        {
            for (int r = 1; r <= y; r++)
            {
                dp[d][r] = 0.7 * dp[d - 1][r] + 0.2 * dp[d - 1][r - 1] + 0.1 * dp[d][r - 1];
            }
        }

        cout << fixed << setprecision(3) << dp[x][y] << "\n";
    }

    return 0;
}