#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll find_min_d(ll a, ll b, int k) {
    ll min_d = LLONG_MAX;

    if (k != 1) {
        if ((k * b - a) >= 0 and (k * b - a) % (k - 1) == 0) {
            ll d = (k * b - a) / (k - 1);

            if (d >= 0 and (a - d) >= 1 and (a - d) <= 99 and (b - d) >= 1 and (b - d) <= 99) {
                min_d = min(min_d, d);
            }
        }

        if ((k * a - b) >= 0 and (k * a - b) % (k - 1) == 0) {
            ll d = (k * a - b) / (k - 1);

            if (d >= 0 and (a - d) >= 1 and (a - d) <= 99 and (b - d) >= 1 and (b - d) <= 99) {
                min_d = min(min_d, d);
            }
        }
    }

    if (k != 0 and 99 % k == 0) {
        ll y = 99 / k;
        if (1 <= y and y <= 99) {
            ll d = b - y;

            if (a > 99) {
                if (d >= 0 and d < (a - 99) and d <= (b - 1) and d >= (b - 99)) {
                    min_d = min(min_d, d);
                }
            }
        }
    }

    if (k == 1) {
        if (a > 99 and b > 99) {
            min_d = min(min_d, 0LL);
        }

        if (a == b and a <= 99 and b <= 99) {
            min_d = min(min_d, 0LL);
        }
    }

    return min_d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        int k;
        cin >> a >> b >> k;
        ll d1 = find_min_d(a, b, k);
        ll d2 = find_min_d(b, a, k);
        ll min_d = LLONG_MAX;

        if (d1 < min_d) {
            min_d = d1;
        }
        if (d2 < min_d) {
            min_d = d2;
        }
        if (min_d != LLONG_MAX) {
            cout << min_d << "\n";
        } else {
            cout << "-1\n";
        }
    }
}