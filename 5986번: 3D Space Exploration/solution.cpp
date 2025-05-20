#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

int N_val;
std::vector<std::vector<std::vector<char>>> space_grid_global;
std::vector<std::vector<std::vector<bool>>> visited_grid_global;

const int dz_global[] = {-1, 1, 0, 0, 0, 0};
const int dy_global[] = {0, 0, -1, 1, 0, 0};
const int dx_global[] = {0, 0, 0, 0, -1, 1};

void bfs_exploration(int start_z, int start_y, int start_x)
{
    std::queue<std::tuple<int, int, int>> q;
    q.push({start_z, start_y, start_x});
    visited_grid_global[start_z][start_y][start_x] = true;

    while (!q.empty())
    {
        auto [current_z, current_y, current_x] = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int next_z = current_z + dz_global[i];
            int next_y = current_y + dy_global[i];
            int next_x = current_x + dx_global[i];

            if (next_z >= 0 && next_z < N_val && next_y >= 0 && next_y < N_val && next_x >= 0 && next_x < N_val)
            {
                if (space_grid_global[next_z][next_y][next_x] == '*' && !visited_grid_global[next_z][next_y][next_x])
                {
                    visited_grid_global[next_z][next_y][next_x] = true;
                    q.push({next_z, next_y, next_x});
                }
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N_val;

    space_grid_global.resize(N_val,
                             std::vector<std::vector<char>>(N_val,
                                                            std::vector<char>(N_val)));

    visited_grid_global.resize(N_val,
                               std::vector<std::vector<bool>>(N_val,
                                                              std::vector<bool>(N_val, false)));

    for (int z = 0; z < N_val; ++z)
    {
        for (int y = 0; y < N_val; ++y)
        {
            std::string row_input_str;
            std::cin >> row_input_str;
            for (int x = 0; x < N_val; ++x)
            {
                space_grid_global[z][y][x] = row_input_str[x];
            }
        }
    }

    int asteroid_count = 0;
    for (int z = 0; z < N_val; ++z)
    {
        for (int y = 0; y < N_val; ++y)
        {
            for (int x = 0; x < N_val; ++x)
            {
                if (space_grid_global[z][y][x] == '*' && !visited_grid_global[z][y][x])
                {
                    asteroid_count++;
                    bfs_exploration(z, y, x);
                }
            }
        }
    }

    std::cout << asteroid_count << "\n";

    return 0;
}