#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    int puzzleNumber = 1;
    bool firstPuzzle = true;
    while (true) {
        cin >> r >> c;
        if (!cin || (r == 0 && c == 0)) break;
        vector<string> grid(r);
        for (int i = 0; i < r; i++)
            cin >> grid[i];

        vector<vector<int>> number(r, vector<int>(c, 0));
        int countNum = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '@') continue;
                bool start = false;
                if ((j == 0 || grid[i][j - 1] == '@') && j + 1 < c && grid[i][j + 1] != '@')
                    start = true;
                if ((i == 0 || grid[i - 1][j] == '@') && i + 1 < r && grid[i + 1][j] != '@')
                    start = true;
                if (start) number[i][j] = countNum++;
            }
        }

        vector<pair<int,int>> across;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '@') continue;
                if ((j == 0 || grid[i][j - 1] == '@') && j + 1 < c && grid[i][j + 1] != '@') {
                    int length = 1;
                    int nj = j + 1;
                    while (nj < c && grid[i][nj] != '@') { length++; nj++; }
                    if (length >= 3) across.push_back({number[i][j], length});
                }
            }
        }

        vector<pair<int,int>> down;
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (grid[i][j] == '@') continue;
                if ((i == 0 || grid[i - 1][j] == '@') && i + 1 < r && grid[i + 1][j] != '@') {
                    int length = 1;
                    int ni = i + 1;
                    while (ni < r && grid[ni][j] != '@') { length++; ni++; }
                    if (length >= 3) down.push_back({number[i][j], length});
                }
            }
        }

        sort(across.begin(), across.end());
        sort(down.begin(), down.end());

        if (!firstPuzzle) cout << "\n";
        firstPuzzle = false;

        cout << "Crossword puzzle " << puzzleNumber++ << "\n";
        cout << "Across\n";
        for (auto &it : across)
            cout << it.first << ".  (" << it.second << ")\n";
        cout << "Down\n";
        for (auto &it : down)
            cout << it.first << ".  (" << it.second << ")\n";
    }
    return 0;
}