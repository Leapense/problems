#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {
    [[nodiscard]]
    bool isPatternPossible(const std::vector<std::vector<int>>& grid)
    {
        const std::size_t n = grid.size();
        const std::size_t m = grid.front().size();

        std::vector<int> rowMax(n, 0);
        std::vector<int> colMax(m, 0);

        for (std::size_t i = 0; i < n; ++i) {
            for (std::size_t j = 0; j < m; ++j) {
                rowMax[i] = std::max(rowMax[i], grid[i][j]);
                colMax[j] = std::max(colMax[j], grid[i][j]);
            }
        }

        for (std::size_t i = 0; i < n; ++i) {
            for (std::size_t j = 0; j < m; ++j) {
                if (rowMax[i] > grid[i][j] && colMax[j] > grid[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t {};
    std::cin >> t;

    for (int caseIdx = 1; caseIdx <= t; ++caseIdx) {
        int n {}, m {};
        std::cin >> n >> m;

        std::vector<std::vector<int>> grid(
            static_cast<std::size_t>(n),
            std::vector<int>(static_cast<std::size_t>(m))
        );

        for (auto& row : grid) {
            for (int& cell : row) {
                std::cin >> cell;
            }
        }

        const bool ok = isPatternPossible(grid);
        std::cout << "Case #" << caseIdx << ": " << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}