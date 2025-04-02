#include "main.h"
#include <iostream>

using namespace std;

vector<long long> count_increasing_subsequences(const vector<int>& A) {
    int N = A.size();
    vector<long long> dp(N, 0);
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    return dp;
}

void solve()
{
    int N; 
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> result = count_increasing_subsequences(A);
    for (int i = 0; i < N; i++) {
        cout << result[i] << (i == N - 1 ? "\n" : " "); 
    }
}

#ifndef UNIT_TESTS
int main()
{
    solve();
    return 0;
}
#endif
