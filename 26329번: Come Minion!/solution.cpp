#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    for (int cs = 0; cs < m; ++cs) {
        int t;
        cin >> t;
        unordered_set<string> forbidden;
        forbidden.reserve(static_cast<size_t>(t) * 2 + 1);
        for (int i = 0; i < t; ++i) {
            string s;
            cin >> s;
            forbidden.insert(s);
        }

        int n, e;
        cin >> n >> e;

        vector<vector<pair<int, string>>> g(n);
        g.shrink_to_fit();
        for (int i = 0; i < e; ++i) {
            int a, b;
            string q;
            cin >> a >> b >> q;
            g[a].push_back({b, q});
            g[b].push_back({a, q});
        }
        vector<char> vis(n, 0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);

        bool ok = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == n - 1) {
                ok = true;
                break;
            }

            for (const auto &nx : g[u]) {
                int v = nx.first;
                const string &lab = nx.second;
                if (vis[v]) continue;
                if (forbidden.find(lab) != forbidden.end()) continue;
                vis[v] = 1;
                q.push(v);
            }
        }

        cout << (ok ? 1 : 0) << '\n';
    }

    return 0;
}