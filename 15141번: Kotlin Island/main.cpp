#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    long long n;
    cin >> h >> w >> n;
    int maxRow = (h + 1) / 2;
    int maxCol = (w + 1) / 2;
    int R = 0, C = 0;
    bool found = false;
    for (int r = 1; r <= maxRow; r++)
    {
        if (n % r != 0)
            continue;
        int c = n / r;
        if (c >= 1 && c <= maxCol)
        {
            R = r;
            C = c;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Impossible";
        return 0;
    }
    vector<string> grid(h, string(w, '#'));
    vector<int> dryRows, dryCols;
    for (int i = 0, cnt = 0; i < h && cnt < R; i++)
    {
        if (cnt == 0 || i - dryRows.back() > 1)
        {
            dryRows.push_back(i);
            cnt++;
        }
    }
    for (int j = 0, cnt = 0; j < w && cnt < C; j++)
    {
        if (cnt == 0 || j - dryCols.back() > 1)
        {
            dryCols.push_back(j);
            cnt++;
        }
    }
    for (int i : dryRows)
        for (int j : dryCols)
            grid[i][j] = '.';
    for (auto &s : grid)
        cout << s << "\n";
    return 0;
}