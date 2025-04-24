#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct E { int to, rev, cap; };
    vector<vector<E>> g;
    Dinic(int n) : g(n) {}
    void add_edge(int u, int v, int c) {
        g[u].push_back({v, (int)g[v].size(), c});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }
    bool bfs(int s, int t, vector<int>& lvl) {
        fill(lvl.begin(), lvl.end(), -1);
        queue<int> q;
        lvl[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : g[v]) if (e.cap && lvl[e.to] == -1) {
                lvl[e.to] = lvl[v] + 1;
                q.push(e.to);
            }
        }
        return lvl[t] != -1;
    }

    int dfs(int v, int t, int f, vector<int>& it, vector<int>& lvl) {
        if (!f || v == t) return f;
        for (int &i = it[v]; i < (int)g[v].size(); ++i) {
            E &e = g[v][i];
            if (e.cap && lvl[e.to] == lvl[v] + 1) {
                int ret = dfs(e.to, t, min(f, e.cap), it, lvl);
                if (ret) { e.cap -= ret; g[e.to][e.rev].cap += ret; return ret; }
            }
        }
        return 0;
    }

    long long maxflow(int s, int t) {
        long long flow = 0;
        vector<int> lvl(g.size()), it(g.size());
        while(bfs(s, t, lvl)) {
            fill(it.begin(), it.end(), 0);
            while(int f = dfs(s, t, INT_MAX, it, lvl)) flow += f;
        }

        return flow;
    }
};

string Solve(istream& in) {
    int n, m;
    if (!(in >> n >> m)) return "";
    vector<int> a(n), b(m);
    for (int& i : a) in >> i;
    for (int& i : b) in >> i;
    long long sa = accumulate(a.begin(), a.end(), 0LL);
    long long sb = accumulate(b.begin(), b.end(), 0LL);

    if (sa != sb) {
        return "NO\n";
    }

    int S = n + m, T = n + m + 1;
    Dinic dinic(T + 1);
    for (int i = 0; i < n; ++i) dinic.add_edge(S, i, a[i]);
    for (int j = 0; j < m; ++j) dinic.add_edge(n + j, T, b[j]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dinic.add_edge(i, n + j, 1);
    if (dinic.maxflow(S, T) != sa) {
        return "NO\n";
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        for (auto &e : dinic.g[i]) {
            if (e.to >= n && e.to < n + m && e.cap == 0) ans.push_back({i + 1, e.to - n + 1});
        }
    }
    ostringstream out;
    out << "YES\n" << ans.size() << "\n";
    for (auto& p : ans) out << p.first << " " << p.second << "\n";
    return out.str();
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << Solve(cin);
    return 0;
}
#endif
