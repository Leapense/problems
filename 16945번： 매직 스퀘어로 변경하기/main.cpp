#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> input(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> input[i][j];
        }
    }

    vector<array<array<int, 3>, 3>> magicSquares = {
        {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}},
        {{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}},
        {{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}},
        {{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}},
        {{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}},
        {{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}},
        {{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}},
        {{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}}};

    int minCost = 1e9;

    for (auto &magic : magicSquares)
    {
        int cost = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cost += abs(input[i][j] - magic[i][j]);
            }
        }

        minCost = min(minCost, cost);
    }

    cout << minCost << endl;

    return 0;
}