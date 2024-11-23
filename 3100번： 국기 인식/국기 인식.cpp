#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> grid(6);
    for (auto &s : grid) cin >> s;

    int min_changes = INT32_MAX;
    for (char top = 'A'; top <= 'Z'; top++) {
        for (char mid = 'A'; mid <= 'Z'; mid++) if (mid != top) {
            for (char bot = 'A'; bot <= 'Z'; bot++) if (bot != mid) {
                int changes = 0;
                for (int i = 0; i < 2; i++) for (char c : grid[i]) if (c != top) changes++;
                for (int i = 2; i < 4; i++) for (char c : grid[i]) if (c != mid) changes++;
                for (int i = 4; i < 6; i++) for (char c : grid[i]) if (c != bot) changes++;

                min_changes = min(min_changes, changes);
            }
        }
    }

    cout << min_changes << "\n";

    return 0;
}