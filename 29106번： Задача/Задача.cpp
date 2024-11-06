#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    ll min_diff = LLONG_MAX;
    ll start = 0;

    for (ll i = 0; i + k <= n; i++) {
        ll diff = a[i + k - 1] - a[i];
        if (diff < min_diff) {
            min_diff = diff;
            start = i;
        }
    }
    for (ll i = start; i < start + k; i++) {
        if (i > start) cout << " ";
        cout << a[i];
    }

    return 0;
}