#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int case_num) {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);

    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    vector<string> result = grid;

    for (int i = 0; i < R - 1; ++i) {
        for (int j = 0; j < C - 1; ++j) {
            if (result[i][j] == '#' && result[i][j+1] == '#' &&
                result[i+1][j] == '#' && result[i+1][j+1] == '#') {
                result[i][j] = '/';
                result[i][j+1] = '\\';
                result[i+1][j] = '\\';
                result[i+1][j+1] = '/';
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (result[i][j] == '#') {
                cout << "Case #" << case_num << ":\nImpossible\n";
                return;
            }
        }
    }

    cout << "Case #" << case_num << ":\n";
    for (const string& row : result) {
        cout << row << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve(t);
    }

    return 0;
}