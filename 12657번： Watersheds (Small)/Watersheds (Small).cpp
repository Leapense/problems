#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int H, W;
vector<vector<int>> altitude;
vector<vector<pair<int, int>>> memo;

pair<int, int> findSink(int i, int j)
{
    if (memo[i][j].first != -1)
        return memo[i][j];
    int current = altitude[i][j];
    int bestVal = current;
    int ni = -1, nj = -1;
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    for (int d = 0; d < 4; d++)
    {
        int ni2 = i + di[d], nj2 = j + dj[d];
        if (ni2 < 0 || ni2 >= H || nj2 < 0 || nj2 >= W)
            continue;
        if (altitude[ni2][nj2] < bestVal)
        {
            bestVal = altitude[ni2][nj2];
            ni = ni2;
            nj = nj2;
        }
    }
    if (ni == -1)
    {
        memo[i][j] = {i, j};
        return memo[i][j];
    }
    pair<int, int> sink = findSink(ni, nj);
    memo[i][j] = sink;
    return sink;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> H >> W;
        altitude.assign(H, vector<int>(W, 0));
        memo.assign(H, vector<pair<int, int>>(W, {-1, -1}));
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> altitude[i][j];
            }
        }
        vector<vector<char>> basin(H, vector<char>(W, ' '));
        vector<vector<pair<int, int>>> sinkMap(H, vector<pair<int, int>>(W, {-1, -1}));
        char currentLabel = 'a';
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                pair<int, int> sink = findSink(i, j);
                sinkMap[i][j] = sink;
            }
        }
        vector<vector<char>> labelForSink(H, vector<char>(W, 0));
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                pair<int, int> sink = sinkMap[i][j];
                if (labelForSink[sink.first][sink.second] == 0)
                {
                    labelForSink[sink.first][sink.second] = currentLabel;
                    currentLabel++;
                }
                basin[i][j] = labelForSink[sink.first][sink.second];
            }
        }
        cout << "Case #" << tc << ":\n";
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cout << basin[i][j] << (j == W - 1 ? "\n" : " ");
            }
        }
    }
    return 0;
}
