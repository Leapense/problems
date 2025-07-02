#include <iostream>
#include <vector>
#include <queue>

bool is_bipartite(int n, const std::vector<std::vector<int>>& adj) {
    std::vector<int> colors(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            std::queue<int> q;
            q.push(i);
            colors[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (colors[v] == -1) {
                        colors[v] = 1 - colors[u];
                        q.push(v);
                    } else if (colors[v] == colors[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n <= 1) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (is_bipartite(n, adj)) {
        std::cout << "POSSIBLE\n";
    } else {
        std::cout << "IMPOSSIBLE\n";
    }

    return 0;
}