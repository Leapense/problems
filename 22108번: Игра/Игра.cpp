#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

bool isGoodGrid(const vector<vector<int>>& grid, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                return true;
            }
            if (i < n - 1 && grid[i][j] == grid[i + 1][j]) {
                return true;
            }
            if (j < n - 1 && grid[i][j] == grid[i][j + 1]) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        if (isGoodGrid(grid, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}