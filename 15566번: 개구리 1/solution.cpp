#include <bits/stdc++.h>
using namespace std;

struct Log { int other; int topic; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; if (!(cin >> n >> m)) return 0;
    array<array<int, 4>, 15> taste{};
    for (int i = 0; i < n; ++i) for (int t = 0; t < 4; ++t) cin >> taste[i][t];

    vector<array<int, 2>> pref(n);
    for (auto &p : pref) { cin >> p[0] >> p[1]; --p[0]; --p[1]; }

    vector<vector<Log>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, t; cin >> a >> b >> t; --a; --b; --t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

    vector<vector<int>> cand(n);
    for (int f = 0; f < n; ++f)
        for (int l : {pref[f][0], pref[f][1]})
            if (find(cand[l].begin(), cand[l].end(), f) == cand[l].end())
                cand[l].push_back(f);

    for (auto &v : cand) if (v.empty()) { cout << "NO\n"; return 0; }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return cand[a].size() < cand[b].size(); });

    vector<int> placed(n, -1);
    function<bool(int, int)> dfs = [&](int idx, int used) -> bool {
        if (idx == n) return true;
        const int l = order[idx];
        for (int f : cand[l]) if (!(used & (1 << f))) {
            bool ok = true;
            for (auto [nb, tp] : adj[l]) if (placed[nb] != -1 &&
                taste[f][tp] != taste[placed[nb]][tp]) { ok = false; break; }
            if (!ok) continue;
            placed[l] = f;
            if (dfs(idx + 1, used | (1 << f))) return true;
            placed[l] = -1;
        }
        return false;
    };

    if (!dfs(0, 0)) { cout << "NO\n"; return 0; }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << placed[i] + 1;
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}