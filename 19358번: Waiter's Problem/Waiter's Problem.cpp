#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll z;
    cin >> z;

    ll total_customers = 0;

    while (z--) {
        ll n;
        cin >> n;
        total_customers += n;

        if (total_customers > 1000000) {

        }

        vector<ll> tips(n);
        for (auto &x : tips) {
            cin >> x;
        }

        sort(tips.begin(), tips.end(), [&](const ll &a, const ll &b) -> bool {
            return a > b;
        });

        ll total_tips = 0;
        for (ll i = 0; i < n; ++i) {
            ll current_tip = tips[i] - i;
            if (current_tip > 0) {
                total_tips += current_tip;
            }
        }

        cout << total_tips << "\n";
    }

    return 0;
}