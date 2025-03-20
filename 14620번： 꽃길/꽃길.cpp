#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> cand;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            cand.push_back({i, j});
        }
    }

    int ans = numeric_limits<int>::max();
    int sz = cand.size();

    for (int a = 0; a < sz; a++)
    {
        for (int b = a + 1; b < sz; b++)
        {
            for (int c = b + 1; c < sz; c++)
            {
                bool used[10][10] = {false};
                int sum = 0;
                bool ok = true;

                for (auto idx : {a, b, c})
                {
                    int i = cand[idx].first, j = cand[idx].second;
                    int di[5] = {0, 1, -1, 0, 0}, dj[5] = {0, 0, 0, 1, -1};

                    for (int k = 0; k < 5; k++)
                    {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni < 0 || ni >= N || nj < 0 || nj >= N || used[ni][nj])
                        {
                            ok = false;
                            break;
                        }

                        used[ni][nj] = true;
                        sum += grid[ni][nj];
                    }

                    if (!ok)
                        break;
                }
                if (ok)
                    ans = min(ans, sum);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}