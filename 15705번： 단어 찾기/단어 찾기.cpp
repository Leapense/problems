#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool checkDirection(const vector<string> &grid, int x, int y, const string &word, int dir)
{
    int N = grid.size(), M = grid[0].size();
    for (int k = 0; k < word.size(); ++k)
    {
        int nx = x + dx[dir] * k;
        int ny = y + dy[dir] * k;

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
            return false;
        }
        if (grid[nx][ny] != word[k])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == S[0])
            {
                for (int d = 0; d < 8; ++d)
                {
                    if (checkDirection(grid, i, j, S, d))
                    {
                        cout << 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}