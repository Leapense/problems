#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    int n = s.length();

    vector<int> heights(n + 1);
    int minHeight = 0, maxHeight = 0;
    int currentHeight = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            currentHeight++;
        } else {
            currentHeight--;
        }

        heights[i + 1] = currentHeight;
        minHeight = min(minHeight, currentHeight);
        maxHeight = max(maxHeight, currentHeight);
    }

    int shift = -minHeight;
    int rows = maxHeight - minHeight;

    vector<string> grid(rows+1, string(n, '.'));

    currentHeight = shift;

    for (int i = 0; i < n; ++i) {
        int row = rows - currentHeight;
        if (s[i] == '(') {
            grid[row - 1][i] = '/';
            currentHeight++;
        } else {
            grid[row][i] = '\\';
            currentHeight--;
        }
    }

    int firstRow = 0;

    while (firstRow < grid.size() && grid[firstRow].find_first_not_of('.') == string::npos) {
        ++firstRow;
    }

    for (int i = firstRow; i < grid.size() - 1; ++i) {
        cout << grid[i] << '\n';
    }

    return 0;
}