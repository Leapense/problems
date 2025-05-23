#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, m, targetX, targetY;
    cin >> n >> m >> targetX >> targetY;

    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (x == targetX && y == targetY)
        {
            cout << dist[x][y];
            return 0;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << "NEVAR";

    return 0;
}