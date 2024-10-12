#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visible(N, vector<bool>(N, false));

    for (int col = 0; col < N; col++) {
        int max_h = -1;
        for (int row = 0; row < N; row++) {
            if (grid[row][col] > 0 and grid[row][col] > max_h) {
                visible[row][col] = true;
                max_h = grid[row][col];
            }
        }
    }

    for (int col = 0; col < N; col++) {
        int max_h = -1;
        for (int row = N - 1; row >= 0; row--) {
            if (grid[row][col] > 0 and grid[row][col] > max_h) {
                visible[row][col] = true;
                max_h = grid[row][col];
            }
        }
    }

    for(int row = 0; row < N; row++) {
        int max_h = -1;
        for (int col = 0; col < N; col++) {
            if (grid[row][col] > 0 and grid[row][col] > max_h) {
                visible[row][col] = true;
                max_h = grid[row][col];
            }
        }
    }

    for (int row = 0; row < N; row++) {
        int max_h = -1;
        for (int col = N - 1; col >= 0; col--) {
            if (grid[row][col] > 0 and grid[row][col] > max_h) {
                visible[row][col] = true;
                max_h = grid[row][col];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visible[i][j]) count++;
        }
    }

    cout << count << "\n";

    return 0;
}