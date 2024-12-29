#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    map<string, int> patternCount;

    for (const string& row : grid) {
        string pattern = row;

        if (pattern[0] == 'T') {
            for (char& c : pattern) {
                c = (c == 'H') ? 'T' : 'H';
            }
        }

        patternCount[pattern]++;
    }

    int maxRows = 0;
    for (const auto& pair : patternCount) {
        maxRows = max(maxRows, pair.second);
    }

    cout << maxRows << "\n";

    return 0;
}