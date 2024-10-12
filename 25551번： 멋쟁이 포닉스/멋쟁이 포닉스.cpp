#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll N, ll TW, ll TB, ll MW, ll MB, ll PW, ll PB, bool startWithWhite) {
    ll w_days = 0, b_days = 0;

    if (startWithWhite) {
        w_days = (N + 1) / 2;
        b_days = N / 2;

        if (w_days > TW || b_days > TB) return false;
        if (w_days > MB || b_days > MW) return false;
        if (w_days > PB || b_days > PW) return false;
    } else {
        w_days = N / 2;
        b_days = (N + 1) / 2;

        if (w_days > TW || b_days > TB) return false;
        if (w_days > MB || b_days > MW) return false;
        if (w_days > PB || b_days > PW) return false;
    }

    return true;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    ll MW, MB, TW, TB, PW, PB;
    cin >> MW >> MB;
    cin >> TW >> TB;
    cin >> PW >> PB;

    ll maxDays = 0;

    ll left = 1, right = 2e9, N1 = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (isPossible(mid, TW, TB, MW, MB, PW, PB, true)) {
            N1 = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 1;
    right = 2e9;
    ll N2 = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (isPossible(mid, TW, TB, MW, MB, PW, PB, false)) {
            N2 = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    maxDays = max(N1, N2);
    cout << maxDays << "\n";

    return 0;
}