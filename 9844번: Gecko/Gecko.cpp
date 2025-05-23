#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;

    vector<vector<int>> mosquitoes(h, vector<int>(w, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> mosquitoes[i][j];
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));

    for (int j = 0; j < w; ++j) {
        dp[0][j] = mosquitoes[0][j];
    }

    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int max_prev = dp[i - 1][j];
            if (j > 0) {
                max_prev = max(max_prev, dp[i - 1][j - 1]);
            }
            if (j < w - 1) {
                max_prev = max(max_prev, dp[i - 1][j + 1]);
            }
            dp[i][j] = max_prev + mosquitoes[i][j];
        }
    }

    int result = 0;
    for (int j = 0; j < w; ++j) {
        result = max(result, dp[h - 1][j]);
    }

    cout << result;
    return 0;
}