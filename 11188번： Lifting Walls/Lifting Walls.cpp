#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, w, n, r;
    cin >> l >> w >> n >> r;

    vector<pair<int, int>> walls(4);
    walls[0] = {-l, 0};
    walls[1] = {l, 0};
    walls[2] = {0, -w};
    walls[3] = {0, w};

    vector<int> crane_masks;

    int x, y;
    int r_scaled = r * 2;
    long long r_sq_scaled = (long long)r_scaled * (long long)r_scaled;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int crane_x_scaled = x * 2;
        int crane_y_scaled = y * 2;
        int mask = 0;

        for (int j = 0; j < 4; j++) {
            long long dx = (long long)(crane_x_scaled) - (long long)(walls[j].first);
            long long dy = (long long)(crane_y_scaled) - (long long)(walls[j].second);
            long long dist_sq = dx * dx + dy * dy;
            if (dist_sq <= r_sq_scaled) {
                mask |= (1 << j);
            }
        }
        crane_masks.push_back(mask);
    }

    vector<int> dp(16, INF);
    dp[0] = 0;

    for (auto mask : crane_masks) {
        vector<int> dp_new = dp;
        for (int state = 0; state < 16; state++) {
            if (dp[state] < INF) {
                int new_state = state | mask;
                if (dp_new[new_state] > dp[state] + 1) {
                    dp_new[new_state] = dp[state] + 1;
                }
            }
        }
        dp = dp_new;
    }

    if (dp[15] < INF) {
        cout << dp[15];
    } else {
        cout << "Impossible";
    }

    return 0;
}