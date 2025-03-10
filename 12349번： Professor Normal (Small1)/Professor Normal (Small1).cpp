#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int M, N;
        cin >> M >> N;
        vector<vector<ll>> grid(M, vector<ll>(N, 0));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> grid[i][j];
            }
        }
        int exchanges = 0;
        set<string> seen;
        while (true)
        {
            bool removed = true;
            while (removed)
            {
                removed = false;
                vector<vector<bool>> removeFlag(M, vector<bool>(N, false));
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (grid[i][j] == -1)
                            continue;
                        if (grid[i][j] < 12)
                        {
                            removeFlag[i][j] = true;
                            continue;
                        }
                        int cnt = 0;
                        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                        for (auto &d : dirs)
                        {
                            int ni = i + d[0], nj = j + d[1];
                            if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] != -1)
                                cnt++;
                        }
                        if (cnt == 0)
                            removeFlag[i][j] = true;
                    }
                }
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (removeFlag[i][j] && grid[i][j] != -1)
                        {
                            grid[i][j] = -1;
                            removed = true;
                        }
                    }
                }
            }
            bool anyChild = false;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] != -1)
                    {
                        anyChild = true;
                        break;
                    }
                }
                if (anyChild)
                    break;
            }
            if (!anyChild)
                break;
            string state;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    state += to_string(grid[i][j]) + ",";
                }
                state += ";";
            }
            if (seen.count(state))
            {
                int cnt = 0;
                for (int i = 0; i < M; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (grid[i][j] != -1)
                            cnt++;
                    }
                }
                cout << "Case #" << tc << ": " << cnt << " children will play forever" << "\n";
                goto nextCase;
            }
            seen.insert(state);
            vector<vector<ll>> newGrid = grid;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == -1)
                        continue;
                    int cnt = 0;
                    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto &d : dirs)
                    {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] != -1)
                            cnt++;
                    }
                    if (cnt > 0)
                        newGrid[i][j] -= 12;
                }
            }
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == -1)
                        continue;
                    int cnt = 0;
                    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto &d : dirs)
                    {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] != -1)
                            cnt++;
                    }
                    if (cnt > 0)
                    {
                        ll share = 12 / cnt;
                        for (auto &d : dirs)
                        {
                            int ni = i + d[0], nj = j + d[1];
                            if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] != -1)
                                newGrid[ni][nj] += share;
                        }
                    }
                }
            }
            grid = newGrid;
            exchanges++;
        }
        cout << "Case #" << tc << ": " << exchanges << " turns" << "\n";
    nextCase:;
    }
    return 0;
}