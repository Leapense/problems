#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll L;

    cin >> n >> L;
    vector<ll> x(n);

    for (auto &e : x) cin >> e;

    vector<ll> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) suffix_sum[i] = suffix_sum[i + 1] + x[i];
    bool stable = true;

    for (int i = 0; i < n - 1 && stable; i++) {
        ll sum = suffix_sum[i + 1];
        int cnt = n - i - 1;

        ll lower = (x[i] - L) * cnt;
        ll upper = (x[i] + L) * cnt;

        if (!(sum > lower && sum < upper)) {
            stable = false;
        }
    }

    cout << (stable ? "stable" : "unstable");

    return 0;
}