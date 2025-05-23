#pragma GCC optimize ("O3,unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

// Function to print the final grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> result(N, vector<int>(N, 0)); // Initialize the result grid
    int count1 = 0, count2 = 0; // Counters for cities in each state

    // Step 1: Assign states using a checkerboard pattern
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Assign based on checkerboard pattern
            if ((i + j) % 2 == 0) {
                result[i][j] = 1; // State 1
                if (grid[i][j] == 'C') count1++;
            } else {
                result[i][j] = 2; // State 2
                if (grid[i][j] == 'C') count2++;
            }
        }
    }

    // Step 2: Balance the cities between the two states if necessary
    if (count1 != count2) {
        // If counts are not balanced, swap the checkerboard pattern
        count1 = count2 = 0; // Reset counts
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // Swap assignments
                result[i][j] = (result[i][j] == 1) ? 2 : 1;
                if (grid[i][j] == 'C') {
                    if (result[i][j] == 1) count1++;
                    else count2++;
                }
            }
        }
    }

    // Step 3: Output the result grid
    printGrid(result);

    return 0;
}