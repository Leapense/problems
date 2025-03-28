#include "main.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<bool, vector<string>> solveBingo(int n, int k)
{
    vector<string> grid;
    if (n == 1)
    {
        if (k == 0)
        {
            grid.push_back(".");
            return {true, grid};
        }
        return {false, grid};
    }
    if (n == 2)
    {
        int maxCells = 1;
        if (k > maxCells)
            return {false, grid};
        grid.assign(n, string(n, '.'));
        if (k == 1)
            grid[0][0] = '#';
        return {true, grid};
    }

    int maxCells = n * (n - 1);
    if (k > maxCells)
        return {false, grid};
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }

    if (n % 2 == 0)
    {
        swap(perm[0], perm[n - 1]);
    }
    grid.assign(n, string(n, '#'));
    for (int i = 0; i < k; i++)
    {
        grid[i][perm[i]] = '.';
    }
    int current = maxCells;

    for (int i = 0; i < n && current > k; i++)
    {
        for (int j = 0; j < n && current > k; j++)
        {
            if (grid[i][j] == '#')
            {
                grid[i][j] = '.';
                current--;
            }
        }
    }

    return {true, grid};
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    auto res = solveBingo(n, k);
    if (!res.first)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (auto &row : res.second)
        {
            cout << row << "\n";
        }
    }
    return 0;
}
#endif