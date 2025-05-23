#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s : grid)
        cin >> s;

    vector<pair<int, int>> emptyCells;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '0')
                emptyCells.push_back({i, j});
        }
    }

    int ans = 1e9;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < emptyCells.size(); i++)
    {
        for (int j = i + 1; j < emptyCells.size(); j++)
        {
            vector<vector<int>> dist(n, vector<int>(m, -1));
            queue<pair<int, int>> q;
            auto add = [&](int r, int c, int d)
            {
                if (r >= 0 && r < n && c >= 0 && c < m && dist[r][c] == -1)
                {
                    dist[r][c] = d;
                    q.push({r, c});
                }
            };

            add(emptyCells[i].first, emptyCells[i].second, 0);
            add(emptyCells[j].first, emptyCells[j].second, 0);

            while (!q.empty())
            {
                auto [r, c] = q.front();
                q.pop();
                for (auto &dir : dirs)
                {
                    int nr = r + dir[0], nc = c + dir[1];
                    add(nr, nc, dist[r][c] + 1);
                }
            }

            int timeMax = 0;
            bool valid = true;

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < m; c++)
                {
                    if (grid[r][c] == '1')
                    {
                        if (dist[r][c] == -1)
                        {
                            valid = false;
                            break;
                        }

                        timeMax = max(timeMax, dist[r][c]);
                    }
                }

                if (!valid)
                    break;
            }

            if (valid)
                ans = min(ans, timeMax);
        }
    }

    cout << ans;

    return 0;
}