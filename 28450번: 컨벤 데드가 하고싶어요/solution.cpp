#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<bool, ll> solve(int N, int M, const vector<vector<ll>>& A, ll H) {
    const ll INF = LLONG_MAX / 4;
    vector<vector<ll>> dp (N, vector<ll>(M, INF));
    dp[0][0] = A[0][0];
    for (int j = 1; j < M; ++j) dp[0][j] = dp[0][j - 1] + A[0][j];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + A[i][0];
        for (int j = 1; j < M; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j];
        }
    }

    ll best = dp[N-1][M-1];
    return {best <= H, best};
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    ll H;
    cin >> H;

    auto [ok, val] = solve(N, M, A, H);
    if (ok) {
        cout << "YES\n" << val << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
#endif
