#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C;
    if (!(std::cin >> R >> C)) return 0;
    std::vector<std::string> grid(R);
    for (auto &row : grid) {
        std::cin >> row;
    }

    int Y, X, K;
    std::cin >> Y >> X >> K;
    char target = grid[Y][X];
    char fill = char('0' + K);
    if (target != fill) {
        std::vector<std::pair<int, int>> q;
        q.reserve((size_t)R * C);
        q.emplace_back(Y, X);
        grid[Y][X] = fill;
        size_t idx = 0;
        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};
        while (idx < q.size()) {
            auto [cy, cx] = q[idx++];
            for (int d = 0; d < 4; d++) {
                int ny = cy + dy[d], nx = cx + dx[d];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C && grid[ny][nx] == target) {
                    grid[ny][nx] = fill;
                    q.emplace_back(ny, nx);
                }
            }
        }
    }

    for (auto &row : grid) {
        std::cout << row << "\n";
    }

    return 0;
}