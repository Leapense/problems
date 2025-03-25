#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "main.h"

using namespace std;

struct Coord
{
    int row, col;
};

int findLargestExoticNumber(const vector<vector<int>> &matrix)
{
    int N = matrix.size();
    unordered_map<int, vector<Coord>> groups;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            groups[matrix[i][j]].push_back({i, j});
        }
    }

    int largestExotic = -1;
    for (auto &entry : groups)
    {
        int value = entry.first;
        auto &coords = entry.second;
        if (coords.size() < 2)
            continue;

        sort(coords.begin(), coords.end(), [](const Coord &a, const Coord &b)
             { return (a.row == b.row) ? a.col < b.col : a.row < b.row; });

        int maxCol = -1;
        bool found = false;

        for (int i = coords.size() - 1; i >= 0; i--)
        {
            if (coords[i].col <= maxCol)
            {
                found = true;
                break;
            }

            maxCol = max(maxCol, coords[i].col);
        }

        if (found)
        {
            largestExotic = max(largestExotic, value);
        }
    }

    return largestExotic;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << findLargestExoticNumber(matrix) << "\n";

    return 0;
}
#endif