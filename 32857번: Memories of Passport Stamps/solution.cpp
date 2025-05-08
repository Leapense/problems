#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

ll compute_min_s(const vector<ll> &p, ll k)
{
    ll lo = 1, hi = 0;
    for (ll x : p)
        hi = max(hi, x);
    while (lo < hi)
    {
        ll mid = lo + (hi - lo) / 2;
        i128 need = 0;
        for (ll x : p)
        {
            need += ((x + mid - 1) / mid);
            if (need > k)
                break;
        }

        if (need <= k)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    if (!(cin >> n >> k))
        return 0;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << compute_min_s(p, k) << endl;
    return 0;
}
#endif