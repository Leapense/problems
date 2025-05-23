#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int digits[10];

        for (int i = 0; i < 10; i++) cin >> digits[i];

        int X;
        cin >> X;

        vector<int> dp(X + 1, INT32_MAX);

        auto can_enter = [&](int num) -> int {
            if (num == 0) {
                return digits[0] ? 1 : INT32_MAX;
            }

            int cnt = 0;

            while (num > 0) {
                if (!digits[num % 10]) return INT32_MAX;
                cnt++;
                num /= 10;
            }

            return cnt;
        };

        for (int i = 1; i <= X; i++) {
            int direct = can_enter(i);
            dp[i] = direct;

            for (int a = 1; a <= sqrt(i); a++) {
                if (i % a == 0) {
                    int b = i / a;

                    if (dp[a] != INT32_MAX && dp[b] != INT32_MAX) {
                        dp[i] = min(dp[i], dp[a] + dp[b] + 1);
                    }
                }
            }
        }
        int result = dp[X] == INT32_MAX ? -1 : dp[X] + 1;
        if (result == -1) cout << "Case #" << tc << ": Impossible\n";
        else cout << "Case #" << tc << ": " << result << "\n";
    }

    return 0;
}