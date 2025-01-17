#include <iostream>
#include <vector>
#include <set>

using namespace std;

int grid[3][3];

vector<pair<int, int>> empty_cells;

int count_solutions = 0;

bool row_used[3][10] = {false};
bool col_used[3][10] = {false};

void backtrack(int idx) {
    if (idx == empty_cells.size()) {
        count_solutions++;
        return;
    }

    int r = empty_cells[idx].first;
    int c = empty_cells[idx].second;

    for (int num = 1; num <= 9; num++) {
        if (!row_used[r][num] && !col_used[c][num]) {
            grid[r][c] = num;
            row_used[r][num] = true;
            col_used[c][num] = true;

            backtrack(idx + 1);

            grid[r][c] = 0;
            row_used[r][num] = false;
            col_used[c][num] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) {
                row_used[i][grid[i][j]] = true;
                col_used[j][grid[i][j]] = true;
            } else {
                empty_cells.emplace_back(i, j);
            }
        }
    }

    backtrack(0);

    cout << count_solutions;

    return 0;
}