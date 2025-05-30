#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <string>

using namespace std;

struct Point { int r, c; };

static constexpr array<int,8> dr = {-2, -2, -1, -1, 1, 1, 2, 2};
static constexpr array<int,8> dc = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    Point start{-1, -1}, goal{-1, -1};

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'K') {
                start = {i, j};
            } else if (grid[i][j] == 'X') {
                goal = {i, j};
            }
        }
    }

    queue<Point> q;
    dist[start.r][start.c] = 0;
    q.push(start);

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if (r == goal.r && c == goal.c) {
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            if (grid[nr][nc] == '#') {
                continue;
            }
            if (dist[nr][nc] != -1) {
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[goal.r][goal.c] << "\n";
    return 0;
}