#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    const int MAX_ID = 100000;
    vector<int> last(MAX_ID + 1);
    vector<int> dp(n + 1, 1);
    int answer = 0;
    for (int day = 1; day <= n; ++day) {
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int id;
            cin >> id;
            int prev = last[id];
            if (prev) dp[day] = max(dp[day], dp[prev] + 1);
            last[id] = day;
        }
        answer = max(answer, dp[day]);
    }

    cout << answer << "\n";
    return 0;
}