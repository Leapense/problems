#include <bits/stdc++.h>
using namespace std;

const int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int ROWS = 3;
const int COLS = 3;

bool isValid (int r, int c) {
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> grid(ROWS);
    for (int i = 0; i < ROWS; ++i) {
        cin >> grid[i];

        if (grid[i].size() != COLS) {
            cerr << "Invalid input row size at row " << i + 1 << "\n";
            return 1;
        }
    }

    string min_word = "ZZZ";

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
            visited[r][c] = true;
            string current_word = "";
            current_word += grid[r][c];

            function<void(int, int, int, string, vector<vector<bool>>)> dfs = [&](int cr, int cc, int depth, string word, vector<vector<bool>> vis) {
                if (depth == 3) {
                    if (word < min_word) {
                        min_word = word;
                    }

                    return;
                }

                for (int dir = 0; dir < 8; ++dir) {
                    int nr = cr + dr[dir];
                    int nc = cc + dc[dir];

                    if (isValid(nr, nc) && !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        dfs(nr, nc, depth + 1, word + string(1, grid[nr][nc]), vis);
                    }
                }
            };

            dfs(r, c, 1, current_word, visited);
        }
    }

    cout << min_word << "\n";

    return 0;
}