#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int minL = 1001, maxR = 0;

    vector<tuple<int, int, int>> rects;

    for (int i = 0; i < N; i++)
    {
        int L, R, H;
        cin >> L >> R >> H;
        minL = min(minL, L);
        maxR = max(maxR, R);
        rects.push_back({L, R, H});
    }

    int width = maxR - minL;
    vector<int> profile(width, 0);
    for (auto &t : rects)
    {
        int L, R, H;
        tie(L, R, H) = t;
        for (int x = L; x < R; x++)
        {
            profile[x - minL] = max(profile[x - minL], H);
        }
    }

    int maxH = 0;
    for (auto h : profile)
        maxH = max(maxH, h);
    int vertical = profile[0] + profile[width - 1];
    for (int i = 0; i < width - 1; i++)
    {
        vertical += abs(profile[i + 1] - profile[i]);
    }

    int horizontal = 0;
    for (auto h : profile)
        if (h > 0)
            horizontal++;

    int perimeter = vertical + horizontal;
    cout << perimeter << "\n";

    vector<vector<char>> grid(maxH, vector<char>(width, '.'));
    if (width > 0 && profile[0] > 0)
    {
        for (int y = 1; y <= profile[0]; y++)
        {
            grid[y - 1][0] = '#';
        }
    }

    if (width > 0 && profile[width - 1] > 0)
    {
        for (int y = 1; y <= profile[width - 1]; y++)
        {
            grid[y - 1][width - 1] = '#';
        }
    }

    for (int i = 0; i < width; i++)
    {
        if (profile[i] > 0)
        {
            grid[profile[i] - 1][i] = '#';
        }
    }

    for (int i = 0; i < width - 1; i++)
    {
        if (profile[i + 1] > profile[i])
        {
            for (int y = max(profile[i], 1); y <= profile[i + 1]; y++)
            {
                grid[y - 1][i + 1] = '#';
            }
        }
        else if (profile[i + 1] < profile[i])
        {
            for (int y = max(profile[i + 1], 1); y <= profile[i]; y++)
            {
                grid[y - 1][i] = '#';
            }
        }
    }

    for (int row = maxH - 1; row >= 0; row--)
    {
        for (int col = 0; col < width; col++)
        {
            cout << grid[row][col];
        }

        cout << "\n";
    }

    for (int i = 0; i < width; i++)
    {
        cout << "*";
    }

    cout << "\n";

    return 0;
}