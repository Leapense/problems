#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int total = n * m;

    if (total % k != 0 || k > total)
    {
        cout << -1;
        return 0;
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<pair<int, int>> path;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                path.push_back({i, j});
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                path.push_back({i, j});
            }
        }
    }

    int pieces = total / k;
    int pieceId = 1;

    for (int i = 0; i < total; i++)
    {
        ans[path[i].first][path[i].second] = pieceId;
        if ((i + 1) % k == 0 && pieceId < pieces)
        {
            pieceId++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << (j == m - 1 ? "\n" : " ");
        }
    }

    return 0;
}