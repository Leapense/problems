#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

bool isPossible(ll k) {
    ll total_cells = k * k;
    ll w1 = (total_cells + 1) / 2;
    ll b1 = total_cells / 2;
    ll w2 = total_cells / 2;
    ll b2 = (total_cells + 1) / 2;

    return ((w1 <= n && b1 <= m) || (w2 <= n && b2 <= m));
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> n >> m;

    ll l = 1, r = 1e9, ans = 0;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (isPossible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}