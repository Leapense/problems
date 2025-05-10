#include <iostream>
#include <vector>
#include <string>
#include <numeric>

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

            int press_at_rc;
            if (current_coin_state == 1)
            {
                press_at_rc = 1;
            }
            else
            {
                press_at_rc = 0;
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int R_rows, C_cols;
    std::cin >> R_rows >> C_cols;

    std::vector<std::string> grid_lines(R_rows);
    for (int i = 0; i < R_rows; ++i)
    {
        std::cin >> grid_lines[i];
    }

    std::cout << solve_coin_flip(R_rows, C_cols, grid_lines) << "\n";

    return 0;
}