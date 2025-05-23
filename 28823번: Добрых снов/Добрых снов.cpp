#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<vector<ll>> families(n + 1);

    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        families[a].push_back(i);
    }

    vector<pair<ll, ll>> positions(n + 1, {0, 0});
    ll current_column = 1;

    for (ll f = 1; f <= n; f++) {
        if (families[f].empty()) continue;

        for (auto &idx : families[f]) {
            positions[idx] = {f, current_column};
            current_column++;
        }
    }

    for (ll i = 1; i <= n; i++) {
        cout << positions[i].first << " " << positions[i].second << "\n";
    }

    return 0;
}