#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr char arrows[] = {'^', '>', 'v', '<'};

bool has_arrow_in_direction(const vector<string>& grid, int x, int y, int dir) {
    int R = grid.size(), C = grid[0].size();
    int nx = x + dx[dir], ny = y + dy[dir];
    while (nx >= 0 && nx < R && ny >= 0 && ny < C) {
        if (grid[nx][ny] != '.') return true;
        nx += dx[dir];
        ny += dy[dir];
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);
        for (auto& row : grid) cin >> row;

        bool impossible = false;
        int answer = 0;
        for (int i = 0; i < R && !impossible; ++i) {
            for (int j = 0; j < C; ++j) {
                char c = grid[i][j];
                if (c == '.') continue;
                int dir = 0;
                while (arrows[dir] != c) ++dir;

                if (has_arrow_in_direction(grid, i, j, dir)) continue;

                bool possible = false;
                for (int d = 0; d < 4; ++d) {
                    if (d == dir) continue;
                    if (has_arrow_in_direction(grid, i, j, d)) {
                        possible = true;
                        break;
                    }
                }

                if (!possible) {
                    impossible = true;
                    break;
                }

                answer++;
            }
        }
        cout << "Case #" << t << ": ";
        if (impossible) cout << "IMPOSSIBLE\n";
        else cout << answer << "\n";
    }

    return 0;
}