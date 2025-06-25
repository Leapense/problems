#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>

// Using a constant for infinity improves readability.
const double INF = std::numeric_limits<double>::max();

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<long long> E(n + 1);
    std::vector<int> S(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> E[i] >> S[i];
    }

    std::vector<std::vector<double>> dist(n + 1, std::vector<double>(n + 1, INF));

    const long long NO_ROUTE = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long d_ij;
            std::cin >> d_ij;
            if (i == j) dist[i][j] = 0;
            else if (d_ij != NO_ROUTE) {
                dist[i][j] = static_cast<double>(d_ij);
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    std::vector<std::vector<double>> time_graph(n + 1, std::vector<double>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) time_graph[i][j] = 0;
            else if (dist[i][j] <= static_cast<double>(E[i])) time_graph[i][j] = dist[i][j] / static_cast<double>(S[i]);
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (time_graph[i][k] != INF && time_graph[k][j] != INF) {
                    time_graph[i][j] = std::min(time_graph[i][j], time_graph[i][k] + time_graph[k][j]);
                }
            }
        }
    }

    for (int k = 0; k < q; ++k) {
        int u, v;
        std::cin >> u >> v;
        if (k > 0) {
            std::cout << " ";
        }
        std::cout << time_graph[u][v];
    }

    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Case #" << i << ": ";
        std::cout << std::fixed << std::setprecision(10);
        solve();
    }

    return 0;
}