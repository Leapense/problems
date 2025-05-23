#include <iostream>
#include <vector>

using namespace std;

int W, H;
vector<string> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, vector<vector<bool>> &visited)
{
    visited[y][x] = true;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H && !visited[ny][nx] && grid[ny][nx] != '#')
        {
            count += dfs(nx, ny, visited);
        }
    }

    return count;
}

int main()
{
    while (cin >> W >> H && (W || H))
    {
        grid.clear();
        grid.resize(H);
        int startX = -1, startY = -1;
        for (int i = 0; i < H; i++)
        {
            cin >> grid[i];
            for (int j = 0; j < W; j++)
            {
                if (grid[i][j] == 'A')
                {
                    startX = j;
                    startY = i;
                }
            }
        }
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        cout << dfs(startX, startY, visited) << "\n";
    }

    return 0;
}