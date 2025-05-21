#include <bits/stdc++.h>
using namespace std;

int computeShortestDistance(const vector<string> &grid,
                            pair<int, int> start,
                            pair<int, int> target)
{
    const int R = grid.size();
    const int C = grid[0].size();
    constexpr int kUnseen = -1;
    vector<vector<int>> dist(R, vector<int>(C, kUnseen));
    queue<pair<int, int>> bfs_queue;

    auto [sr, sc] = start;
    dist[sr][sc] = 0;
    bfs_queue.push(start);

    constexpr int dr[4] = {-1, +1, 0, 0};
    constexpr int dc[4] = {0, 0, -1, +1};

    while (!bfs_queue.empty())
    {
        auto [r, c] = bfs_queue.front();
        bfs_queue.pop();

        if (make_pair(r, c) == target)
        {
            return dist[r][c];
        }

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            {
                continue;
            }
            if (grid[nr][nc] == '*' || dist[nr][nc] != kUnseen)
            {
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            bfs_queue.emplace(nr, nc);
        }
    }

    return kUnseen;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R = 0;
    int C = 0;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; ++i)
    {
        cin >> grid[i];
    }

    pair<int, int> cow_pos{-1, -1};
    pair<int, int> barn_pos{-1, -1};

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (grid[r][c] == 'C')
            {
                cow_pos = {r, c};
            }
            else if (grid[r][c] == 'B')
            {
                barn_pos = {r, c};
            }
        }
    }

    const int distance = computeShortestDistance(grid, cow_pos, barn_pos);
    const int munches = (distance > 0 ? distance : 0);
    cout << munches << "\n";

    return EXIT_SUCCESS;
}