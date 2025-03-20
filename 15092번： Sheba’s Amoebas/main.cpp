#include <iostream>
#include <vector>
#include <string>
using namespace std;
int m, n;
vector<string> grid;
vector<vector<bool>> visited;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 8; k++)
    {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj] == '#')
            dfs(ni, nj);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    grid.resize(m);
    for (int i = 0; i < m; i++)
        cin >> grid[i];
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
    cout << count;
    return 0;
}