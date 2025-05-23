#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, caseNo = 1;
    while (cin >> N)
    {
        vector<string> grid(N);
        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }
        int count = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        function<void(int, int)> dfs = [&](int i, int j)
        {
            if (i < 0 || j < 0 || i >= N || j >= N)
                return;
            if (grid[i][j] == '0' || visited[i][j])
                return;
            visited[i][j] = true;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                        continue;
                    dfs(i + di, j + dj);
                }
            }
        };
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(i, j);
                }
            }
        }
        cout << "Case #" << caseNo++ << ": " << count << "\n";
    }
    return 0;
}
