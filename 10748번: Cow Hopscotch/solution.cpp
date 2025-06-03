#include <cassert>
#include <cinttypes>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::int32_t;
using std::int64_t;
using std::vector;

static constexpr int32_t MODULO = 1e9 + 7;
static constexpr int MAX_DIM = 100;

static inline int32_t modAdd(int32_t lhs, int32_t rhs) {
    int64_t temp = static_cast<int64_t>(lhs) + rhs;
    int32_t result = static_cast<int32_t>(temp % MODULO);
    if (result < 0) {
        result += MODULO;
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t rows = 0;
    int32_t cols = 0;
    int32_t maxLabel = 0;

    cin >> rows >> cols >> maxLabel;
    assert(rows >= 2 && rows <= MAX_DIM);
    assert(cols >= 2 && cols <= MAX_DIM);
    assert(maxLabel >= 1 && maxLabel <= rows * cols);

    vector<vector<int32_t>> grid(rows, vector<int32_t>(cols));
    for (int32_t r = 0; r < rows; ++r) {
        for (int32_t c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }

    vector<vector<int32_t>> dp(rows, vector<int32_t>(cols, 0));
    dp[0][0] = 1;

    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int32_t sumPaths = 0;
            const int32_t currentLabel = grid[i][j];

            for (int32_t r = 0; r < i; ++r) {
                for (int32_t c = 0; c < j; ++c) {
                    if (grid[r][c] != currentLabel) {
                        sumPaths = modAdd(sumPaths, dp[r][c]);
                    }
                }
            }

            dp[i][j] = sumPaths;
        }
    }

    int32_t answer = dp[rows - 1][cols - 1] % MODULO;
    cout << answer << "\n";

    return 0;
}