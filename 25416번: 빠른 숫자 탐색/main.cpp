#include <iostream>
#include <queue>
#include <array>

using namespace std;

int main()
{
    array<array<int, 5>, 5> board;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    int sr, sc;
    cin >> sr >> sc;

    queue<tuple<int, int, int>> q;
    array<array<bool, 5>, 5> vis = {false};

    q.push({sr, sc, 0});
    vis[sr][sc] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [r, c, dist] = q.front();
        q.pop();

        if (board[r][c] == 1)
        {
            cout << dist;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !vis[nr][nc] && board[nr][nc] != -1)
            {
                vis[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }

    cout << -1;
    return 0;
}