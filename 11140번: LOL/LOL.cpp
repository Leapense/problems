#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &a, const string &b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j - 1],
                                    dp[i][j - 1],
                                    dp[i - 1][j]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string word;
        cin >> word;

        if (word.find("lol") != string::npos) {
            cout << "0\n";
            continue;
        }

        int min_cost = 3;
        int N = word.size();

        for (int i = 0; i < N; i++) {
            if (word[i] == 'l') {
                if (i + 1 < N && word[i + 1] == 'l') {
                    min_cost = min(min_cost, 1);
                }

                if (i + 2 < N) {
                    if (word[i + 1] == 'o' && word[i + 2] == 'l') {
                        min_cost = min(min_cost, 0);
                    } else {
                        if (word[i + 2] == 'l') {
                            min_cost = min(min_cost, 1);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                string substring = word.substr(i, j - i + 1);
                int ed = edit_distance(substring, "lol");
                min_cost = min(min_cost, ed);
                if (min_cost == 0) break;
            }
            if (min_cost == 0) break;
        }

        cout << min_cost << "\n";
    }
    return 0;
}