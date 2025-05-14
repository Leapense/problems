#include <iostream>
#include <vector>
#include <string>

double calculate_ascii_shape_area(int h, int w, const std::vector<std::string>& grid)
{
    double total_area = 0.0;

    for (int r = 0; r < h; ++r)
    {
        int num_boundaries_crossed_in_row = 0;
        for (int c = 0; c < w; ++c)
        {
            char current_char = grid[r][c];
            if (current_char == '/' || current_char == '\\')
            {
                total_area += 0.5;
                num_boundaries_crossed_in_row++;
            }
            else
            {
                if (num_boundaries_crossed_in_row % 2 == 1)
                {
                    total_area += 1.0;
                }
            }
        }
    }

    return total_area;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w;
    std::cin >> h >> w;

    std::vector<std::string> grid_input(h);
    for (int i = 0; i < h; ++i)
    {
        std::cin >> grid_input[i];
    }

    double result = calculate_ascii_shape_area(h, w, grid_input);

    std::cout << result << std::endl;
    return 0;
}