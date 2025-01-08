#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cx, cy, n;
    cin >> cx >> cy >> n;

    vector<double> v;
    int inside = 0;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        double dx = x - cx;
        double dy = y - cy;
        double d = sqrt(dx * dx + dy * dy);
        if (d < r) inside++;
        else v.push_back(d - r);
    }

    if (inside >= 3) {
        cout << 0 << "\n";
        return 0;
    }

    sort(v.begin(), v.end());
    int need = 3 - inside;
    if (need > (int)v.size()) {
        cout << (int)floor(v.back()) << "\n";
        return 0;
    }

    cout << (int)floor(v[need - 1]) << "\n";

    return 0;
}