#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a) cin >> x;

    vector<int> count_p(n, 0);

    for (ll i = 0; i < n; i++) {
        int ai = a[i];

        int low = max(1, ai - 1);
        int high = min((int)n, ai + 1);

        for (int si = low; si <= high; si++) {
            ll p = ((i - (ll)(si - 1)) % n + n) % n;
            count_p[p]++;
        }
    }

    ll possible_p = -1;

    for (ll p = 0; p < n; p++) {
        if (count_p[p] == n) {
            possible_p = p;
            break;
        }
    }

    if (possible_p != -1) {
        cout << "YES\n" << (possible_p + 1) << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}