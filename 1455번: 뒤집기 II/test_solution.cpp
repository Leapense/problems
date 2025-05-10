#include "gtest/gtest.h"
#include <vector>
#include <string>

int solve_coin_flip(int R, int C, const std::vector<std::string> &initial_grid_str)
{
    std::vector<std::vector<int>> initial_grid(R, std::vector<int>(C));
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            initial_grid[i][j] = initial_grid_str[i][j] - '0';
        }
    }

    std::vector<std::vector<int>> tpa(R + 1, std::vector<int>(C + 1, 0));
    int flip_operations_count = 0;

    for (int r = R - 1; r >= 0; --r)
    {
        for (int c = C - 1; c >= 0; --c)
        {
            int accumulated_effect_from_others = tpa[r + 1][c] ^ tpa[r][c + 1] ^ tpa[r + 1][c + 1];
            int current_coin_state = initial_grid[r][c] ^ accumulated_effect_from_others;

            int press_at_rc = 0;
            if (current_coin_state == 1)
            {
                press_at_rc = 1;
            }

            if (press_at_rc == 1)
            {
                flip_operations_count++;
            }

            tpa[r][c] = press_at_rc ^ tpa[r + 1][c] ^ tpa[r][c + 1] ^ tpa[r + 1][c + 1];
        }
    }

    return flip_operations_count;
}

TEST(CoinFlipTest, Sample1)
{
    std::vector<std::string> grid = {"00", "01"};
    EXPECT_EQ(solve_coin_flip(2, 2, grid), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}