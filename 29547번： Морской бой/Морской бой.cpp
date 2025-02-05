#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> forbidden(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                if (forbidden[x][y])
                {
                    cout << "INCORRECT";
                    return 0;
                }
            }
        }

        int ex1 = max(1, x1 - 1);
        int ey1 = max(1, y1 - 1);
        int ex2 = min(n, x2 + 1);
        int ey2 = min(m, y2 + 1);

        for (int x = ex1; x <= ex2; x++)
        {
            for (int y = ey1; y <= ey2; y++)
            {
                forbidden[x][y] = true;
            }
        }
    }

    long long count = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (!forbidden[x][y])
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}