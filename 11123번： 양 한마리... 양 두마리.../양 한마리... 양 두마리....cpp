#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int H, W;
        cin >> H >> W;
        vector<string> grid(H);
        for (int i = 0; i < H; i++)
        {
            cin >> grid[i];
        }
        int flocks = 0;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        auto dfs = [&](auto &dfs, int i, int j) -> void
        {
            visited[i][j] = true;
            int di[4] = {1, -1, 0, 0};
            int dj[4] = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++)
            {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && grid[ni][nj] == '#')
                {
                    dfs(dfs, ni, nj);
                }
            }
        };

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!visited[i][j] && grid[i][j] == '#')
                {
                    flocks++;
                    dfs(dfs, i, j);
                }
            }
        }

        cout << flocks << "\n";
    }

    return 0;
}