#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> posA(n + 1, -1), posB(n + 1, -1);
    for (int i = 0; i < n; i++) {
        posA[a[i]] = i;
        posB[b[i]] = i;
    }
    for (int x = 1; x <= n - 1; x++) {
        bool ra = posA[x] < posA[x + 1];
        bool rb = posB[x] < posB[x + 1];
        if (ra != rb) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<int> cur = a;
    fill(posA.begin(), posA.end(), -1);
    for (int i = 0; i < n; i++) posA[cur[i]] = i;

    vector<int> ops;
    ops.reserve(20000);

    for (int i = 0; i < n; i++) {
        int t = b[i];
        int p = posA[t];
        while (p > i) {
            int lv = cur[p - 1];
            int rv = cur[p];
            if (abs(lv - rv) < 2) { cout << -1 << '\n'; return 0; }
            if (ops.size() >= 20000) { cout << -1 << '\n'; return 0; }
            swap(cur[p - 1], cur[p]);
            posA[cur[p]] = p;
            posA[cur[p - 1]] = p;
            ops.push_back(p);
            --p;
        }
    }

    cout << ops.size() << '\n';

    if (!ops.empty()) {
        for (size_t i = 0; i < ops.size(); i++) {
            if (i) cout << ' ';
            cout << ops[i];
        }

        cout << '\n';
    }

    return 0;
}