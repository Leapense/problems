#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, R, C;

vector<vector<char>> grid;

void draw(int n, int r, int c)
{
    int h = 4 * n - 1;
    int w = 4 * n - 3;
    if (n == 1)
    {
        grid[r][c] = '*';
        return;
    }

    for (int j = c; j < c + w; j++)
        grid[r][j] = '*';
    for (int j = c; j < c + w; j++)
        grid[r + h - 1][j] = '*';
    for (int i = r; i < r + h; i++)
        grid[i][c] = '*';
    draw(n - 1, r + 2, c + 2);
    for (int j = c + 2; j < c + w; j++)
        grid[r + 2][j] = '*';
    for (int i = r + 2; i < r + h - 1; i++)
        grid[i][c + w - 1] = '*';
    for (int i = r + 3; i < r + h - 2; i++)
        grid[i][c + 2] = '*';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    R = 4 * N - 1;
    C = 4 * N - 3;
    grid.assign(R, vector<char>(C, ' '));
    draw(N, 0, 0);
    for (auto &row : grid)
    {
        int pos = C - 1;
        while (pos >= 0 && row[pos] == ' ')
            pos--;
        if (pos < 0)
            cout << "\n";
        else
        {
            for (int j = 0; j <= pos; j++)
                cout << row[j];
            cout << "\n";
        }
    }

    return 0;
}