#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> p(6, 0);
    for (int d = 1; d <= 5; d++)
    {
        cin >> p[d];
    }

    vector<vector<int>> problems(6);
    for (int i = 0; i < N; i++)
    {
        int d, t;
        cin >> d >> t;
        problems[d].push_back(t);
    }

    long long totalTime = 0;

    for (int d = 1; d <= 5; d++)
    {
        sort(problems[d].begin(), problems[d].end());
        int m = problems[d].size();
        int need = p[d];

        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            prefix[i + 1] = prefix[i] + problems[d][i];
        }

        long long bestCost = LLONG_MAX;

        for (int i = 0; i + need - 1 < m; i++)
        {
            int j = i + need - 1;
            long long sumSegment = prefix[j + 1] - prefix[i];
            long long diff = problems[d][j] - problems[d][i];
            long long cost = sumSegment + diff;
            bestCost = min(bestCost, cost);
        }

        totalTime += bestCost;
    }

    totalTime += 60LL * 4;
    cout << totalTime << "\n";

    return 0;
}