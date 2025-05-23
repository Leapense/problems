#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);

    int max_a = 0;
    for (auto &x : a) {
        cin >> x;
        if (x > max_a) max_a = x;
    }

    vector<int> freq(max_a + 1, 0);
    for (auto x : a) {
        freq[x]++;
    }
    vector<ll> total(max_a + 1, 0);
    for (int x = 1; x <= max_a; x++) {
        for (int m = x; m <= max_a; m += x) {
            total[x] += freq[m];
        }
    }

    ll res = 0;
    for (int x = 1; x <= max_a; x++) res += (ll)freq[x] * (total[x] - 1);
    cout << res << "\n";

    return 0;
}