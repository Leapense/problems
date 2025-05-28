#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    pair<int, int> start{-1, -1}, target{-1, -1};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'z') {
                start = {i, j};
            } else if (grid[i][j] == 'n') {
                target = {i, j};
            }
        }
    }

    constexpr array<pair<int, int>, 8> kMoves = {{
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
    }};

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == target.first && c == target.second) {
            break;
        }

        for (auto [dr, dc] : kMoves) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (grid[nr][nc] == 'x' || dist[nr][nc] != -1) {
                continue;
            }
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    int answer = dist[target.first][target.second];
    if (answer < 0) {
        cout << "NIE\n";
    } else {
        cout << answer << "\n";
    }

    return 0;
}