#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> b(n);
    for (auto &x : b)
        cin >> x;

    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        ll diff = a[i] - b[i];
        res = gcd(res, diff);
    }

    cout << res << endl;

    return 0;
}