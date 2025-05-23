#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);

    int max_len = 0;
    for (auto &s : words) {
        cin >> s;
        max_len = max(max_len, (int)s.length());
    }

    int left = 1, right = max_len;
    int answer = max_len;

    auto check = [&](int W) -> bool {
        vector<vector<bool>> dp(n + 1, vector<bool>(2, false));

        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int v = 0; v <= 1; v++) {
                if (dp[i][v]) {
                    if ((int)words[i].length() <= W) {
                        dp[i + 1][0] = true;
                    }
                    if (v == 0) {
                        dp[i + 1][1] = true;
                    }
                }
            }
        }

        return dp[n][0] || dp[n][1];
    };

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}