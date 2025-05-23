#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    for (int case_num = 1; case_num <= num_cases; ++case_num) {
        int n, m;
        long long X, Y, Z;
        cin >> n >> m >> X >> Y >> Z;

        vector<long long> A(m);
        for (int i = 0; i < m; ++i) {
            cin >> A[i];
        }
        vector<long long> S(n);
        vector<long long> current_A = A;
        for (int i = 0; i < n; ++i) {
            S[i] = current_A[i % m];
            current_A[i % m] = (X * current_A[i % m] + Y * (i + 1)) % Z;
        }

        long long MOD = 1000000007;
        vector<long long> dp(n, 0);
        long long total_increasing_subsequences = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (S[j] < S[i]) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }

            total_increasing_subsequences = (total_increasing_subsequences + dp[i]) % MOD;
        }

        cout << "Case #" << case_num << ": " << total_increasing_subsequences << endl;
    }

    return 0;
}