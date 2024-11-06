#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n);

    for (auto &x : a) cin >> x;
    vector<ll> b(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        b[i + 1] = a[i - 1] - b[i - 1] - b[i];
    }

    for (int i = 0; i < n + 2; i++) {
        if (i > 0) cout << " ";
        cout << b[i];
    }

    return 0;
}