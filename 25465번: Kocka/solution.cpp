#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using Grid = std::vector<std::vector<int>>;

void update_projections(int r, int c, int d, int n, const std::vector<int>& cube_data, Grid& proj_front, Grid& proj_back, Grid& proj_left, Grid& proj_right) {
    auto get_cube_color = [&](int x, int y, int z) {
        return cube_data[((size_t)x * n + y) * n + z];
    };

    int color = 0;
    for (int k = 0; k < n; ++k) {
        if (get_cube_color(r, c, k) != 0) {
            color = get_cube_color(r, c, k);
            break;
        }
    }

    proj_front[r][c] = color;

    color = 0;
    int back_view_c = (n - 1) - c;
    for (int k = 0; k < n; ++k) {
        if (get_cube_color(r, c, (n - 1) - k) != 0) {
            color = get_cube_color(r, c, (n - 1) - k);
            break;
        }
    }

    proj_back[r][back_view_c] = color;

    color = 0;
    int left_view_c = (n - 1) - d;
    for (int k = 0; k < n; ++k) {
        if (get_cube_color(r, k, d) != 0) {
            color = get_cube_color(r, k, d);
            break;
        }
    }
    proj_left[r][left_view_c] = color;

    color = 0;
    int right_view_c = d;
    for (int k = 0; k < n; ++k) {
        if (get_cube_color(r, (n - 1) - k, d) != 0) {
            color = get_cube_color(r, (n - 1) - k, d);
            break;
        }
    }
    proj_right[r][right_view_c] = color;
}

void print_grid(const Grid& grid) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            std::cout << grid[i][j] << (j == grid[i].size() - 1 ? "" : " ");
        }

        std::cout << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> cube_data((size_t)n * n * n, 0);
    Grid proj_front(n, std::vector<int>(n, 0));
    Grid proj_back(n, std::vector<int>(n, 0));
    Grid proj_left(n, std::vector<int>(n, 0));
    Grid proj_right(n, std::vector<int>(n, 0));

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int r, c, d, color;
            std::cin >> r >> c >> d >> color;
            r--;
            c--;
            d--;

            cube_data[((size_t)r * n + c) * n + d] = color;
            update_projections(r, c, d, n, cube_data, proj_front, proj_back, proj_left, proj_right);
        } else {
            std::string side;
            std::cin >> side;
            if (side == "prednja") {
                print_grid(proj_front);
            } else if (side == "straznja") {
                print_grid(proj_back);
            } else if (side == "lijeva") {
                print_grid(proj_left);
            } else if (side == "desna") {
                print_grid(proj_right);
            }
        }
    }

    return 0;
}