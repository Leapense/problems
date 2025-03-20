#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> grid(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<long long> rowMax(n, 0), colMax(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rowMax[i] = max(rowMax[i], grid[i][j]);
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            colMax[j] = max(colMax[j], grid[i][j]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != rowMax[i] && grid[i][j] != colMax[j])
            {
                ans += grid[i][j];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}