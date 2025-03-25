#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Color
{
    int r, g, b;
};

int N;
vector<Color> colors;
Color target;
int minDiff = 1e9;

void dfs(int idx, int count, int sumR, int sumG, int sumB)
{
    if (count >= 2)
    {
        int mixR = sumR / count;
        int mixG = sumG / count;
        int mixB = sumB / count;

        int diff = abs(mixR - target.r) + abs(mixG - target.g) + abs(mixB - target.b);
        minDiff = min(minDiff, diff);
    }
    if (count == 7 || idx == N)
        return;

    for (int i = idx; i < N; i++)
    {
        dfs(i + 1, count + 1, sumR + colors[i].r, sumG + colors[i].g, sumB + colors[i].b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    colors.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> colors[i].r >> colors[i].g >> colors[i].b;
    }
    cin >> target.r >> target.g >> target.b;

    dfs(0, 0, 0, 0, 0);
    cout << minDiff << "\n";

    return 0;
}