#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);
        for (int i = 0; i < R; i++)
        {
            cin >> grid[i];
        }
        int ans = 0;
        bool possible = true;
        auto checkSafe = [&](int i, int j, char d) -> bool
        {
            if (d == '^')
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (grid[k][j] != '.')
                        return true;
                }
            }
            else if (d == 'v')
            {
                for (int k = i + 1; k < R; k++)
                {
                    if (grid[k][j] != '.')
                        return true;
                }
            }
            else if (d == '<')
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (grid[i][k] != '.')
                        return true;
                }
            }
            else if (d == '>')
            {
                for (int k = j + 1; k < C; k++)
                {
                    if (grid[i][k] != '.')
                        return true;
                }
            }
            return false;
        };
        for (int i = 0; i < R && possible; i++)
        {
            for (int j = 0; j < C && possible; j++)
            {
                if (grid[i][j] == '.')
                    continue;
                if (!checkSafe(i, j, grid[i][j]))
                {
                    if (!(checkSafe(i, j, '^') || checkSafe(i, j, 'v') || checkSafe(i, j, '<') || checkSafe(i, j, '>')))
                    {
                        possible = false;
                        break;
                    }
                    ans++;
                }
            }
        }
        cout << "Case #" << t << ": ";
        if (!possible)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << "\n";
    }
    return 0;
}
