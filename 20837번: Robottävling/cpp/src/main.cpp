#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace
{
    bool dfs(int row, const vector<vector<int>> &graph, vector<int> &matchR, vector<bool> &seen)
    {
        for (int col : graph[row])
        {
            if (!seen[col])
            {
                seen[col] = true;
                if (matchR[col] == -1 || dfs(matchR[col], graph, matchR, seen))
                {
                    matchR[col] = row;
                    return true;
                }
            }
        }

        return false;
    }
}

std::pair<int, int> computeCubeCounts(int N, const vector<int> &r, const vector<int> &c)
{
    int maxSum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            maxSum += min(r[i], c[j]);
        }
    }

    int baseline = N * N;
    int rowExtra = 0, colExtra = 0;

    for (int i = 0; i < N; i++)
    {
        rowExtra += (r[i] - 1);
    }
    for (int j = 0; j < N; j++)
    {
        colExtra += (c[j] - 1);
    }

    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (r[i] == c[j])
            {
                graph[i].push_back(j);
            }
        }
    }

    vector<int> matchR(N, -1);
    int saving = 0;
    for (int i = 0; i < N; i++)
    {
        vector<bool> seen(N, false);
        if (dfs(i, graph, matchR, seen))
        {
            saving += (r[i] - 1);
        }
    }

    int minSum = baseline + (rowExtra + colExtra - saving);
    return {minSum, maxSum};
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> r(N), c(N);

    for (int i = 0; i < N; i++)
        cin >> r[i];
    for (int j = 0; j < N; j++)
        cin >> c[j];

    auto result = computeCubeCounts(N, r, c);
    cout << result.first << " " << result.second << "\n";

    return 0;
}
#endif