#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

#define MAX_DIM 100
static const int32_t MODULO = 1000000007;

/* modAdd 함수도 그대로 사용 */
static inline int32_t modAdd(int32_t a, int32_t b)
{
    int64_t temp = (int64_t)a + b;
    temp %= MODULO;
    if (temp < 0) {
        temp += MODULO;
    }
    return (int32_t)temp;
}

int main(void)
{
    int32_t rows    = 0;
    int32_t columns = 0;
    int32_t maxLabel= 0;

    if (scanf("%" SCNd32 " %" SCNd32 " %" SCNd32, &rows, &columns, &maxLabel) != 3) {
        return EXIT_FAILURE;
    }
    assert(rows >= 2 && rows <= MAX_DIM);
    assert(columns >= 2 && columns <= MAX_DIM);
    assert(maxLabel >= 1 && maxLabel <= rows * columns);

    /* 배열 크기를 매크로로 지정했으므로, 초기자도 허용된다 */
    int32_t grid[MAX_DIM][MAX_DIM] = { { 0 } };
    for (int32_t r = 0; r < rows; r++) {
        for (int32_t c = 0; c < columns; c++) {
            int32_t value = 0;
            if (scanf("%" SCNd32, &value) != 1) {
                return EXIT_FAILURE;
            }
            grid[r][c] = value;
        }
    }

    int32_t dp[MAX_DIM][MAX_DIM] = { { 0 } };
    dp[0][0] = 1;

    for (int32_t i = 0; i < rows; i++) {
        for (int32_t j = 0; j < columns; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int32_t sumPaths       = 0;
            const int32_t currLabel = grid[i][j];

            for (int32_t r = 0; r < i; r++) {
                for (int32_t c = 0; c < j; c++) {
                    if (grid[r][c] != currLabel) {
                        sumPaths = modAdd(sumPaths, dp[r][c]);
                    }
                }
            }
            dp[i][j] = sumPaths;
        }
    }

    int32_t result = dp[rows - 1][columns - 1] % MODULO;
    printf("%" PRId32 "\n", result);
    return EXIT_SUCCESS;
}