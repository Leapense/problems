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

    while (T--) {
        ll a, b, S;
        cin >> a >> b >> S;
        if (S > a * b) {
            cout << "NO\n";
            continue;
        }

        bool ok = false;

        for (ll c = 1; c * c <= S; c++) {
            if (S % c != 0) continue;
            ll d = S / c;
            if ((c <= a and d <= b) or (c <= b and d <= a)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}