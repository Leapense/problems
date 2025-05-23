#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> T(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> S(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + T[i - 1];
    }

    deque<int> dq;
    dq.push_back(0);

    ll max_sum = LLONG_MIN;

    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && dq.front() < i - m) {
            dq.pop_front();
        }

        if (!dq.empty()) {
            ll current_sum = S[i] - S[dq.front()];
            if(current_sum > max_sum) {
                max_sum = current_sum;
            }
        }

        while (!dq.empty() && S[dq.back()] >= S[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    if (max_sum == LLONG_MIN) {
        max_sum = 0;
    }

    cout << max_sum << "\n";

    return 0;
}