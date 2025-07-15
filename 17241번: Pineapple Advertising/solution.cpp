#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<bool> converted(n + 1, false);

    for (int i = 0; i < q; ++i) {
        int target_house;
        std::cin >> target_house;

        long long newly_converted_count = 0;
        if (!converted[target_house]) {
            converted[target_house] = true;
            newly_converted_count++;
        }

        std::vector<int> remaining_neighbors;
        remaining_neighbors.reserve(adj[target_house].size());

        for (int neighbor : adj[target_house]) {
            if (converted[neighbor]) {
                remaining_neighbors.push_back(neighbor);
            } else {
                converted[neighbor] = true;
                newly_converted_count++;
            }
        }
        
        adj[target_house] = std::move(remaining_neighbors);

        std::cout << newly_converted_count << "\n";
    }
}

int main() {
    solve();
    return 0;
}