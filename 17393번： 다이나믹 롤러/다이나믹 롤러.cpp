#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    vector<ll> A(N), B(N);

    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<ll> res(N, 0);

    for (ll i = 0; i < N; i++) {
        ll pos = upper_bound(B.begin() + i + 1, B.end(), A[i]) - B.begin();
        res[i] = pos - (i + 1);
        if (res[i] < 0) res[i] = 0;
    }

    for (ll i = 0; i < N; i++) cout << res[i] << (i < N - 1 ? " " : "\n");

    return 0;
}