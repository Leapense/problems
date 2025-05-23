#include <iostream>
#include <vector>

using namespace std;

int m, n;

vector<string> grid;
vector<vector<bool>> visited;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == '#')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    grid.resize(m);

    for (int i = 0; i < m; i++)
    {
        cin >> grid[i];
    }
    visited.assign(m, vector<bool>(n, false));
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#' && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}