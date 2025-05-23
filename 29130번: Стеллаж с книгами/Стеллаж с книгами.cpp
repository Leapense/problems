#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // A predefined valid 3x3 block pattern
    vector<vector<int>> pattern = {
        {1, 2, 3},
        {4, 5, 1},
        {2, 3, 4}
    };
    
    // Create the grid
    vector<vector<int>> grid(n, vector<int>(m));

    // Fill the grid by repeating the 3x3 pattern
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = pattern[i % 3][j % 3];
        }
    }

    // Output the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}