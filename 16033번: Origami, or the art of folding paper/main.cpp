#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n, m, t, p;
        cin >> n >> m >> t >> p;

        if (n == 0 && m == 0 && t == 0 && p == 0)
            break;

        vector<vector<int>> grid(m, vector<int>(n, 1));

        int curW = n, curH = m;

        for (int i = 0; i < t; i++)
        {
            int d, c;
            cin >> d >> c;

            if (d == 1)
            {
                int newW = max(curW - c, c);
                vector<vector<int>> newGrid(curH, vector<int>(newW, 0));

                for (int y = 0; y < curH; y++)
                {
                    for (int x = 0; x < curW; x++)
                    {
                        if (x < c)
                        {
                            int nx = c - x - 1;
                            newGrid[y][nx] += grid[y][x];
                        }
                        else
                        {
                            int nx = x - c;
                            newGrid[y][nx] += grid[y][x];
                        }
                    }
                }

                grid = move(newGrid);
                curW = newW;
            }
            else
            {
                int newH = max(curH - c, c);
                vector<vector<int>> newGrid(newH, vector<int>(curW, 0));

                for (int y = 0; y < curH; y++)
                {
                    for (int x = 0; x < curW; x++)
                    {
                        if (y < c)
                        {
                            int ny = c - y - 1;
                            newGrid[ny][x] += grid[y][x];
                        }
                        else
                        {
                            int ny = y - c;
                            newGrid[ny][x] += grid[y][x];
                        }
                    }
                }

                grid = move(newGrid);
                curH = newH;
            }
        }

        for (int i = 0; i < p; i++)
        {
            int x, y;
            cin >> x >> y;
            cout << grid[y][x] << "\n";
        }
    }

    return 0;
}