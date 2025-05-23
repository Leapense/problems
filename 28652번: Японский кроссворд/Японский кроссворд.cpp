#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n, m;
    cin >> n >> m;

    cin.ignore();

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, grid[i]);
    }

    for (int i = 0; i < n; ++i) {
        vector<int> sequences;
        int count = 0;

        for(int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                count++;
            } else {
                if (count > 0) {
                    sequences.push_back(count);
                    count = 0;
                }
            }
        }

        if (count > 0) {
            sequences.push_back(count);
        }

        cout << sequences.size();

        if (!sequences.empty()) {
            for (int k = 0; k < sequences.size(); ++k) {
                cout << ' ' << sequences[k];
            }
        }

        cout << '\n';
    }

    cout << '\n';

    for (int j = 0; j < m; ++j) {
        vector<int> sequences;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '#') {
                count++;
            } else {
                if (count > 0) {
                    sequences.push_back(count);
                    count = 0;
                }
            }
        }

        if (count > 0) {
            sequences.push_back(count);
        }

        cout << sequences.size();

        if (!sequences.empty()) {
            for (int k = 0; k < sequences.size(); ++k) {
                cout << ' ' << sequences[k];
            }
        }

        cout << '\n';
    }
    return 0;
}