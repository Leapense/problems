#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &x : A) {
        cin >> x;
    }

    ll dp_prev_no = 0;
    ll dp_prev_yes = 1;

    for (int i = 1; i < N; i++) {
        ll new_dp0 = INF;
        ll new_dp1 = INF;

        if (A[i] > A[i - 1]) {
            new_dp0 = min(new_dp0, dp_prev_no);
        }

        if (A[i] > A[i - 1] + K) {
            new_dp0 = min(new_dp0, dp_prev_yes);
        }

        if (A[i] + K > A[i - 1]) {
            new_dp1 = min(new_dp1, dp_prev_no + 1);
        }

        if (A[i] + K > A[i - 1] + K) {
            new_dp1 = min(new_dp1, dp_prev_yes + 1);
        }

        dp_prev_no = new_dp0;
        dp_prev_yes = new_dp1;
    }

    ll res = min(dp_prev_no, dp_prev_yes);
    if (res >= INF) {
        cout << "-1\n";
    } else {
        cout << res << "\n";
    }

    return 0;
}