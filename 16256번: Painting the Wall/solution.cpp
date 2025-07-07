#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<int>> g(n, std::vector<int>(m));
        for (auto &row : g) {
            for (int &cell : row) {
                std::cin >> cell;
            }
        }

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int run = 0;
            for (int j = 0; j < m; ++j) {
                run = g[i][j] ? run + 1 : 0;
                mx = std::max(mx, run);
            }
        }
        for (int j = 0; j < m; ++j) {
            int run = 0;
            for (int i = 0; i < n; ++i) {
                run = g[i][j] ? run + 1 : 0;
                mx = std::max(mx, run);
            }
        }

        if (mx > k) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int out = g[i][j] ? (i + j) % k + 1 : 0;
                std::cout << out << (j + 1 < m ? ' ' : '\n');
            }
        }
    }

    return 0;
}