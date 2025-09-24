#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    auto dyn2idx = [](const string& s) -> int {
        if (s == "ppp") return 0;
        if (s == "pp") return 1;
        if (s == "p") return 2;
        if (s == "mp") return 3;
        if (s == "mf") return 4;
        if (s == "f") return 5;
        if (s == "ff") return 6;
        return 7;
    };

    vector<int> starts(m), levv(m);
    for (int k = 0; k < m; ++k) {
        int idx; string d;
        cin >> idx >> d;

        starts[k] = idx - 1;
        levv[k] = dyn2idx(d);
    }

    vector<int> lev(n);
    for (int k = 0; k < m; ++k) {
        int L = starts[k];
        int R = (k + 1 < m ? starts[k + 1] : n) - 1;
        for (int i = L; i <= R; ++i) lev[i] = levv[k];
    }

    array<vector<long long>, 8> bucket;
    for (int i = 0; i < 8; ++i) bucket[i].clear();
    for (int i = 0; i < n; ++i) {
        bucket[lev[i]].push_back(a[i]);
    }
    for (int i = 0; i < 8; ++i) sort(bucket[i].begin(), bucket[i].end());

    long long ans = 0;
    for (int l = 0; l < 8; ++l) {
        for (int r = l + 1; r < 8; ++r) {
            const auto& L = bucket[l];
            const auto& R = bucket[r];
            size_t i = 0, szL = L.size();
            for (long long y : R) {
                while(i < szL && L[i] < y) ++i;
                ans += (long long)(szL - i);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}