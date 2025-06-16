#include <iostream>
#include <vector>
#include <numeric>

constexpr int EMPTY = 0;
constexpr int VISITED = 1;
constexpr int OBSTACLE = 2;

const int dr[] = {0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, -1, 1};

bool is_valid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void solve() {
    int R, C;
    std::cin >> R >> C;
    std::vector<std::vector<int>> grid(R, std::vector<int>(C, EMPTY));

    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int br, bc;
        std::cin >> br >> bc;
        grid[br][bc] = OBSTACLE;
    }

    int curr_r, curr_c;
    std::cin >> curr_r >> curr_c;
    grid[curr_r][curr_c] = VISITED;

    std::vector<int> directions(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> directions[i];
    }

    int dir_idx = 0;
    while (true) {
        bool can_move_at_all = false;
        for (int i = 0; i < 4; ++i) {
            int d = directions[i];
            int next_r = curr_r + dr[d];
            int next_c = curr_c + dc[d];
            if (is_valid(next_r, next_c, R, C) && grid[next_r][next_c] == EMPTY) {
                can_move_at_all = true;
                break;
            }
        }

        if (!can_move_at_all) {
            break;
        }

        int current_direction = directions[dir_idx];
        while (true) {
            int next_r = curr_r + dr[current_direction];
            int next_c = curr_c + dc[current_direction];

            if (is_valid(next_r, next_c, R, C) && grid[next_r][next_c] == EMPTY) {
                curr_r = next_r;
                curr_c = next_c;
                grid[curr_r][curr_c] = VISITED;
            } else {
                break;
            }
        }

        dir_idx = (dir_idx + 1) % 4;
    }

    std::cout << curr_r << " " << curr_c << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}