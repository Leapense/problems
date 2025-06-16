#include <iostream>
#include <vector>
#include <string>
#include <queue>

void bfs(int start_r, int start_c, int r_max, int c_max, const std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited) {
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    std::queue<std::pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
        auto [curr_r, curr_c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];

            if (next_r >= 0 && next_r < r_max &&
                next_c >= 0 && next_c < c_max &&
                !visited[next_r][next_c] && grid[next_r][next_c] != 'W') {
                    visited[next_r][next_c] = true;
                    q.push({next_r, next_c});
                }
        }
    }
}

void solve() {
    int r, c;
    if (!(std::cin >> r >> c)) return;

    std::vector<std::string> grid(r);
    for (int i = 0; i < r; ++i) {
        std::cin >> grid[i];
    }

    std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));
    int island_count = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'L' && !visited[i][j]) {
                island_count++;
                bfs(i, j, r, c, grid, visited);
            }
        }
    }
    std::cout << island_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}