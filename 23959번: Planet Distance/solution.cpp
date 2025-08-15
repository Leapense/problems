#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        vector<int> deg(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            ++deg[x];
            ++deg[y];
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (deg[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (deg[u] > 0) {
                    --deg[u];
                    if (deg[u] == 1) q.push(u);
                }
            }
            deg[v] = 0;
        }

        vector<int> dist(N + 1, -1);
        queue<int> q2;
        for (int i = 1; i <= N; ++i) {
            if (deg[i] > 0) {
                dist[i] = 0;
                q2.push(i);
            }
        }

        while (!q2.empty()) {
            int v = q2.front();
            q2.pop();
            for (int u : adj[v]) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    q2.push(u);
                }
            }
        }

        cout << "Case #" << tc << ":";
        for (int i = 1; i <= N; ++i) {
            cout << ' ' << dist[i];
        }

        cout << '\n';
    }

    return 0;
}