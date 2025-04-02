#include <iostream>
#include <vector>

using namespace std;

constexpr long long MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> dp(N, 0);

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dp[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
