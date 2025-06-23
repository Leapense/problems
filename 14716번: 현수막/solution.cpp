#include <iostream>
#include <vector>

using namespace std;

static const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
static const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    auto dfs = [&](auto&& self, int r, int c) -> void {
        visited[r][c] = true;
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                if (!visited[nr][nc] && grid[nr][nc] == 1) {
                    self(self, nr, nc);
                }
            }
        }
    };

    int letter_count = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && grid[i][j] == 1) {
                ++letter_count;
                dfs(dfs, i, j);
            }
        }
    }

    cout << letter_count << "\n";
    return 0;
}