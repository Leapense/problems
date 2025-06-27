#include <iostream>
#include <vector>
#include <queue>
#include <utility>

struct Point {
    int row;
    int col;
};

void solve() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    std::vector<std::vector<int>> distances(n, std::vector<int>(m, -1));
    Point start_node = {-1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> map[i][j];
            if (map[i][j] == 2) {
                start_node = {i, j};
            } else if (map[i][j] == 0) {
                distances[i][j] = 0;
            }
        }
    }

    std::queue<Point> q;
    if (start_node.row != -1) {
        distances[start_node.row][start_node.col] = 0;
        q.push(start_node);
    }

    const std::vector<Point> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int next_row = current.row + dir.row;
            int next_col = current.col + dir.col;

            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && map[next_row][next_col] == 1 && distances[next_row][next_col] == -1) {
                distances[next_row][next_col] = distances[current.row][current.col] + 1;
                q.push({next_row, next_col});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << distances[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}