#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int M, N, M1, M2;
    cin >> M >> N >> M1 >> M2;

    vector<vector<int>> grid(M, vector<int>(N));
    int startX, startY, destX, destY;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 3)
            {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 4)
            {
                destX = i;
                destY = j;
            }
        }
    }

    vector<pair<int, int>> moves = {{M1, M2}, {M1, -M2}, {-M1, M2}, {-M1, -M2}, {M2, M1}, {M2, -M1}, {-M2, M1}, {-M2, -M1}};
    vector<vector<int>> dist(M, vector<int>(N, -1));
    queue<pair<int, int>> q;
    dist[startX][startY] = 0;
    q.push({startX, startY});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (x == destX && y == destY)
        {
            cout << dist[x][y];
            return 0;
        }
        for (auto &mv : moves)
        {
            int nx = x + mv.first, ny = y + mv.second;
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (grid[nx][ny] == 0 || grid[nx][ny] == 2)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}