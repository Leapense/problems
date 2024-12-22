#include <bits/stdc++.h>
using namespace std;

bool searchWord(const vector<string>& grid, const string& word) {
    int n = 8;
    int word_len = word.length();
    vector<pair<int, int>> directions = {{0,1},{1,0},{1,1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &[di, dj] : directions) {
                int end_i = i + (word_len - 1) * di;
                int end_j = j + (word_len - 1) * dj;
                if (end_i >= n || end_j >= n) {
                    continue;
                }

                bool match = true;
                for (int k = 0; k < word_len; ++k) {
                    if (grid[i + k * di][j + k * dj] != word[k]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (auto &word : words) {
            cin >> word;
        }

        vector<string> grid(8);
        for (int i = 0; i < 8; ++i) {
            cin >> grid[i];
        }

        bool all_found = true;

        for (auto &word : words) {
            if (!searchWord(grid, word)) {
                all_found = false;
                break;
            }
        }

        if (all_found) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}