#include <iostream>
#include <vector>
#include <array>

using Grid = std::array<std::array<bool, 105>, 105>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C;
    std::cin >> C;

    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int R;
        std::cin >> R;

        Grid grid{}, nextGrid{};

        for (auto &row : grid) {
            row.fill(false);
        }

        for (int i = 0; i < R; ++i) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            for (int y = y1; y <= y2; ++y) {
                for (int x = x1; x <= x2; ++x) {
                    grid[y][x] = true;
                }
            }
        }

        int seconds = 0;
        while (true) {
            bool anyAlive = false;
            for (int y = 0; y < 105; ++y) {
                for (int x = 0; x < 105; ++x) {
                    bool north = (y > 0) && grid[y - 1][x];
                    bool west = (x > 0) && grid[y][x - 1];
                    if (grid[y][x]) {
                        nextGrid[y][x] = north || west;
                    } else {
                        nextGrid[y][x] = north && west;
                    }

                    anyAlive = anyAlive || nextGrid[y][x];
                }
            }

            ++seconds;

            if (!anyAlive) {
                break;
            }

            grid = nextGrid;
        }

        std::cout << "Case #" << caseNum << ": " << seconds << "\n";
    }

    return 0;
}