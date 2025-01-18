#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll c, e, m;
    cin >> c >> e >> m;

    if (c != 4) {
        cout << "impossible";
        return 0;
    }

    if (m > 0) {
        ll sqrtm = sqrt((double)m);

        for (ll d = 1; d <= sqrtm; d++) {
            if (m % d == 0) {
                ll h = d + 2;
                ll w = m / d + 2;
                if (w >= h && 2 <= h && 2 <= w && 2 * w + 2 * h - 8 == e) {
                    cout << w << " " << h;

                    return 0;
                }
            }
        }

        cout << "impossible";
    } else {
        if ((e + 4) % 2 != 0) {
            cout << "impossible";
            return 0;
        }

        ll w = (e + 4) / 2;
        if (w >= 2) {
            cout << w << " " << 2;
        } else {
            cout << "impossible";
        }
    }

    return 0;
}