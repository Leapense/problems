#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int puzzle = 1; puzzle <= t; puzzle++) {
        int r, c;
        cin >> r >> c;

        vector<string> grid(r);
        for (int i = 0; i < r; i++) {
            cin >> grid[i];
        }

        int s;
        cin >> s;

        vector<string> words(s);
        for (int i = 0; i < s; i++) {
            cin >> words[i];
        }

        cout << "Word search puzzle #" << puzzle << ":\n";

        vector<pair<char, pair<int, int>>> directions = {
            {'R', {0, 1}},
            {'L', {0, -1}},
            {'D', {1, 0}},
            {'U', {-1, 0}}
        };

        for (const auto &word : words) {
            bool found = false;

            for (int i = 0; i < r && !found; i++) {
                for (int j = 0; j < c && !found; j++) {
                    if (grid[i][j] != word[0]) continue;

                    for (auto &dir : directions) {
                        char dCode = dir.first;
                        int dr = dir.second.first;
                        int dc = dir.second.second;

                        bool match = true;
                        int curR = i;
                        int curC = j;

                        for (int k = 0; k < word.size(); k++) {
                            if (grid[curR][curC] != word[k]) {
                                match = false;
                                break;
                            }

                            curR = (curR + dr + r) % r;
                            curC = (curC + dc + c) % c;
                        }

                        if (match) {
                            cout << dCode << " " << (i + 1) << " " << (j + 1) << " " << word << "\n";
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}