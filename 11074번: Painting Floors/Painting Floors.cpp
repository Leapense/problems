#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    string grid[m];
    for (int i = 0; i < m; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.' && (j == 0 || grid[i][j - 1] == 'x'))
            {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }

    return 0;
}