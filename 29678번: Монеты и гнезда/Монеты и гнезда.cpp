#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n);
    for (auto &x : b) cin >> x;

    vector<pair<int, int>> nests;

    for(int i = 0; i < n; i++) {
        int need = b[i] - a[i];
        nests.emplace_back(need, a[i]);
    }

    sort(nests.begin(), nests.end());

    for (auto &[need, ai] : nests) {
        if (m >= need) {
            m += ai;
        }
    }

    cout << m << endl;

    return 0;
}