#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int surfaceArea = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] > 0)
            {
                surfaceArea += 2;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int d = 0; d < 4; ++d)
            {
                int ni = i + dx[d];
                int nj = j + dy[d];
                int neighborHeight = 0;
                if (ni >= 0 && ni < N && nj >= 0 && nj < M)
                {
                    neighborHeight = grid[ni][nj];
                }

                surfaceArea += max(grid[i][j] - neighborHeight, 0);
            }
        }
    }

    cout << surfaceArea << "\n";

    return 0;
}