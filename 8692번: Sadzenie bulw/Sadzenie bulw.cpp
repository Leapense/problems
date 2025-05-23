#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b)
        cin >> x;
    ll m;
    cin >> m;
    sort(b.begin(), b.end(), greater<ll>());
    ll sum = 0;
    for (auto x : b)
    {
        if (m == 0)
            break;
        ll k = min(x, m);
        sum += k * k;
        m -= k;
    }
    cout << sum;

    return 0;
}