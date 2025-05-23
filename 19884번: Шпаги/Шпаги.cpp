#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<pair<long long, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {a[i], i};

    sort(v.begin(), v.end(), [](auto &x, auto &y) {return x.first > y.first;});

    if (n > 1 && v[0].first == v[1].first) {
        cout << -1 << "\n";
        return 0;
    }
    
    vector<int> p(n, -1), cap(n, 2);
    queue<int> q;
    q.push(0);

    for (int i = 1; i < n; i++) {
        if (q.empty()) {
            cout << -1 << "\n";
            return 0;
        }

        int r = q.front();
        if (v[r].first >= v[i].first + k) {
            p[v[i].second] = v[r].second;
            cap[r]--;
            if (cap[r] == 0) q.pop();
            q.push(i);
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] < 0) cout << 0 << " ";
        else cout << p[i] + 1 << " ";
    }

    cout << "\n";

    return 0;
}