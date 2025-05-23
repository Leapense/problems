#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Coord
{
    int row, col;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, vector<Coord>> groups;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int val;
            cin >> val;
            groups[val].push_back({i, j});
        }
    }

    int largestExotic = -1;

    for (auto &entry : groups)
    {
        const int value = entry.first;
        auto &coords = entry.second;

        if (coords.size() < 2)
        {
            continue;
        }

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

    cout << largestExotic << "\n";

    return 0;
}