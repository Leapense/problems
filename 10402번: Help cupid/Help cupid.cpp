#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculate_time_difference(int tz1, int tz2) {
    int diff = abs(tz1 - tz2);
    return min(diff, 24 - diff);
}

int main() {
    int n;
    cin >> n;

    vector<int> timezones(n);
    for (int i = 0; i < n; ++i) {
        cin >> timezones[i];
    }

    sort(timezones.begin(), timezones.end());

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // 초기화를 INT_MAX로 수정

    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (len == 2) { // 기저 사례 처리 추가
                dp[i][j] = calculate_time_difference(timezones[i], timezones[j]);
            } else {
                for (int k = i + 1; k <= j; k += 2) {
                    int current_diff = calculate_time_difference(timezones[i], timezones[k]);
                    int prev_diff = (k == i + 1) ? 0 : dp[i + 1][k - 1];
                    int remaining_diff = (k == j) ? 0 : dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], current_diff + prev_diff + remaining_diff);
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}