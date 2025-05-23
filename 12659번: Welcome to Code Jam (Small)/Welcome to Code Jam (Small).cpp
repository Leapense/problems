#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string target = "welcome to code jam";
const int MOD = 10000;

int countSubsequences(const string& input) {
    int m = target.length();
    int n = input.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (target[i - 1] == input[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
            } else {
                dp[i][j] = dp[i][j - 1] % MOD;
            }
        }
    }

    return dp[m][n];
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 1; i <= N; ++i) {
        string input;
        getline(cin, input);
        int result = countSubsequences(input);

        cout << "Case #" << i << ": " << setw(4) << setfill('0') << result << endl;
    }

    return 0;
}