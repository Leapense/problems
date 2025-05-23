#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> rowCount(N, 0), colCount(M, 0);
    long long totalPawns = 0;

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            if (row[j] == '#')
            {
                rowCount[i]++;
                colCount[j]++;
                totalPawns++;
            }
        }
    }

    if (totalPawns == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    long long maxRow = 0, maxCol = 0;
    for (int i = 0; i < N; i++)
    {
        maxRow = max(maxRow, rowCount[i]);
    }
    for (int j = 0; j < M; j++)
    {
        maxCol = max(maxCol, colCount[j]);
    }

    long long answer = 2LL * totalPawns - (maxRow + maxCol);
    cout << answer << "\n";

    return 0;
}