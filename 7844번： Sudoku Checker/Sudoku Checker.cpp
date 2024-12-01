#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int size = N * N;

    vector<vector<int>> grid(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        vector<bool> seen(size + 1, false);

        for (int j = 0; j < size; j++) {
            int val = grid[i][j];
            if (val != 0) {
                if (val < 1 || val > size || seen[val]) {
                    cout << "INCORRECT";
                    return 0;
                }

                seen[val] = true;
            }
        }
    }

    for (int j = 0; j < size; j++) {
        vector<bool> seen(size + 1, false);
        for (int i = 0; i < size; i++) {
            int val = grid[i][j];
            if (val != 0) {
                if (val < 1 || val > size || seen[val]) {
                    cout << "INCORRECT";
                    return 0;
                }
                seen[val] = true;
            }
        }
    }

    for (int block_i = 0; block_i < N; block_i++) {
        for (int block_j = 0; block_j < N; block_j++) {
            vector<bool> seen(size + 1, false);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int val = grid[block_i * N + i][block_j * N + j];
                    if (val != 0) {
                        if (val < 1 || val > size || seen[val]) {
                            cout << "INCORRECT";
                            return 0;
                        }
                        seen[val] = true;
                    }
                }
            }
        }
    }

    cout << "CORRECT";

    return 0;
}