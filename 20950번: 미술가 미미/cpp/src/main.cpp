#include <iostream>
#include "main.h"
#include <vector>

using namespace std;

namespace
{
    int minDiff;

    void dfs(int idx, int count, int sumR, int sumG, int sumB, const vector<Color> &colors, const Color &target)
    {
        if (count >= 2)
        {
            int mixR = sumR / count;
            int mixG = sumG / count;
            int mixB = sumB / count;

            int diff = abs(mixR - target.r) + abs(mixG - target.g) + abs(mixB - target.b);
            minDiff = min(minDiff, diff);
        }

        if (count == 7 || idx == static_cast<int>(colors.size()))
            return;

        for (int i = idx; i < static_cast<int>(colors.size()); i++)
        {
            dfs(i + 1, count + 1, sumR + colors[i].r, sumG + colors[i].g, sumB + colors[i].b, colors, target);
        }
    }
}

int computeMinDifference(const vector<Color> &colors, const Color &target)
{
    minDiff = 1e9;
    dfs(0, 0, 0, 0, 0, colors, target);
    return minDiff;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Color> colors(N);

    for (int i = 0; i < N; i++)
    {
        cin >> colors[i].r >> colors[i].g >> colors[i].b;
    }

    Color target;
    cin >> target.r >> target.g >> target.b;
    cout << computeMinDifference(colors, target) << "\n";

    return 0;
}
#endif