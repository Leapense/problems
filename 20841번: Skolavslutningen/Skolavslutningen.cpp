#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<string> grid(N);
    for (auto &s : grid) cin >> s;

    int total = K + M;
    vector<vector<int>> adj(total, vector<int>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int class_idx = grid[i][j] - 'A';
            int col_idx = K + j;
            adj[class_idx].push_back(col_idx);
            adj[col_idx].push_back(class_idx);
        }
    }

    vector<bool> visited(total, false);
    int components = 0;

    for (int i = 0; i < total; i++) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);

            visited[i] = true;

            while(!q.empty()) {
                int u = q.front(); q.pop();
                for (auto &v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << components << endl;
    return 0;
}