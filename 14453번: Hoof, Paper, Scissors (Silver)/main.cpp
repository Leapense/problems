#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<char> moves(N);
    for (int i = 0; i < N; i++)
    {
        cin >> moves[i];
    }

    auto winCount = [&](char b, char f) -> int
    {
        if (b == 'H' && f == 'S')
            return 1;
        if (b == 'P' && f == 'H')
            return 1;
        if (b == 'S' && f == 'P')
            return 1;
        return 0;
    };

    vector<vector<int>> prefix(N + 1, vector<int>(3, 0));
    vector<vector<int>> suffix(N + 1, vector<int>(3, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            prefix[i][j] = prefix[i - 1][j];
        }
        prefix[i][0] += winCount('H', moves[i - 1]);
        prefix[i][1] += winCount('P', moves[i - 1]);
        prefix[i][2] += winCount('S', moves[i - 1]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            suffix[i][j] = suffix[i + 1][j];
        }
        suffix[i][0] += winCount('H', moves[i]);
        suffix[i][1] += winCount('P', moves[i]);
        suffix[i][2] += winCount('S', moves[i]);
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ans = max(ans, prefix[i][j] + suffix[i][k]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}