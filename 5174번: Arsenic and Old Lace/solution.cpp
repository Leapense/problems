#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    for (int dataSet = 1; dataSet <= K; ++dataSet)
    {
        int s, b;
        cin >> s >> b;
        vector<bitset<50>> base(b);
        for (int i = 0; i < b; ++i)
        {
            string line;
            cin >> line;
            for (int j = 0; j < s; ++j)
                if (line[j] == 'y')
                    base[i][j] = 1;
        }

        string poisonStr;
        cin >> poisonStr;
        bitset<50> poison;

        for (int j = 0; j < s; ++j)
        {
            if (poisonStr[j] == 'y')
                poison[j] = 1;
        }

        int minCnt = INT_MAX;
        for (int mask = 1; mask < (1 << b); ++mask)
        {
            bitset<50> comb;
            int cnt = 0;
            for (int i = 0; i < b; ++i)
            {
                if (mask & (1 << i))
                {
                    comb |= base[i];
                    ++cnt;
                }
            }

            if (comb == poison)
                minCnt = min(minCnt, cnt);
        }

        cout << "Data Set " << dataSet << ":\n";
        if (minCnt == INT_MAX)
            cout << "Impossible.\n";
        else
            cout << minCnt << "\n";
        cout << "\n";
    }

    return 0;
}