#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        ll n, m, p, q, t;
        cin >> n >> m >> p >> q >> t;

        ll c1 = t / p, c2 = t / q;

        c1 = max(c1, (ll)1), c2 = max(c2, (ll)1);

        ll best = LLONG_MAX;
        ll max_x = min(n, c1);

        for (ll x = 0; x <= max_x; x++) {
            ll remaining_time = t - x * p;
            if (remaining_time < 0) continue;

            ll y_max = min(m, remaining_time / q);
            ll y = y_max;
            ll need_n = n > x ? n - x : 0;
            ll need_m = m > y ? m - y : 0;
            ll a = (need_n + c1 - 1) / c1;
            ll b = (need_m + c2 - 1) / c2;

            a = max(a, (ll)0), b = max(b, (ll)0);

            ll total = a + b + 1;

            best = min(best, total);
        }

        ll max_y = min(m, c2);
        for (ll y = 0; y <= max_y; y++) {
            ll remaining_time = t - y * q;
            if (remaining_time < 0) continue;
            ll x_max = min(n, remaining_time / p);
            ll x = x_max;
            ll need_n = n > x ? n - x : 0;
            ll need_m = m > y ? m - y : 0;
            ll a = (need_n + c1 - 1) / c1;
            ll b = (need_m + c2 - 1) / c2;

            a = max(a, (ll)0), b = max(b, (ll)0);
            ll total = a + b + 1;
            best = min(best, total);
        }

        cout << best << "\n";
    }

    return 0;
}