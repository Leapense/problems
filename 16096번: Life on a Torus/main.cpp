#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int m, n;
        cin >> m >> n;

        vector<string> grid(m);

        for (int i = 0; i < m; i++)
        {
            cin >> grid[i];
        }

        unordered_map<string, int> seen;

        auto toString = [&](const vector<string> &g) -> string
        {
            string s;
            for (auto &row : g)
            {
                s += row;
            }

            return s;
        };

        string state = toString(grid);
        int t = 0;
        while (seen.find(state) == seen.end())
        {
            seen[state] = t;

            vector<string> next(grid);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int count = 0;
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            if (di == 0 && dj == 0)
                                continue;
                            int ni = (i + di + m) % m;
                            int nj = (j + dj + n) % n;
                            if (grid[ni][nj] == 'o')
                                count++;
                        }
                    }
                    if (count <= 1 || count >= 4)
                        next[i][j] = 'x';
                    else if (count == 3)
                        next[i][j] = 'o';
                    else
                        next[i][j] = grid[i][j];
                }
            }

            grid = next;
            state = toString(grid);
            t++;
        }
        cout << t - seen[state] << "\n";
    }

    return 0;
}