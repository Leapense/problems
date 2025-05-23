#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);

    for (auto &s : grid) cin >> s;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool possible = true;

    for (int i = 0; i < R && possible; i++) {
        for (int j = 0; j < C && possible; j++) {
            if (grid[i][j] == 'W') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        if (grid[ni][nj] == 'S') {
                            possible = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (!possible) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') grid[i][j] = 'D';
            }
        }

        cout << "1\n";
        for (auto &s : grid) cout << s << "\n";
    }

    return 0;
}