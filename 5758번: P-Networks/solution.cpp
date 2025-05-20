#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve_p_networks()
{
    while (true)
    {
        int n;
        std::cin >> n;
        if (n == 0)
        {
            break;
        }

        std::vector<int> targets_raw(n);
        std::vector<bool> seen_target_wires(n + 1, false);
        bool is_valid_permutation_spec = true;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> targets_raw[i];
            if (targets_raw[i] < 1 || targets_raw[i] > n)
            {
                is_valid_permutation_spec = false;
            }
            else
            {
                if (seen_target_wires[targets_raw[i]])
                {
                    is_valid_permutation_spec = false;
                }
                seen_target_wires[targets_raw[i]] = true;
            }
        }

        if (!is_valid_permutation_spec)
        {
            std::cout << "No solution" << std::endl;
            continue;
        }

        std::vector<int> final_config(n);
        for (int original_wire_0_idx = 0; original_wire_0_idx < n; ++original_wire_0_idx)
        {
            int original_wire_1_idx = original_wire_0_idx + 1;
            int destination_physical_wire_1_idx = targets_raw[original_wire_0_idx];
            final_config[destination_physical_wire_1_idx - 1] = original_wire_1_idx;
        }

        std::vector<int> current_config(n);
        std::iota(current_config.begin(), current_config.end(), 1);

        std::vector<int> strokes_applied;

        for (int k_target_wire_0_idx = 0; k_target_wire_0_idx < n; ++k_target_wire_0_idx)
        {
            int value_to_place = final_config[k_target_wire_0_idx];

            int current_pos_of_value_0_idx = -1;
            for (int j = k_target_wire_0_idx; j < n; ++j)
            {
                if (current_config[j] == value_to_place)
                {
                    current_pos_of_value_0_idx = j;
                    break;
                }
            }

            while (current_pos_of_value_0_idx > k_target_wire_0_idx)
            {
                std::swap(current_config[current_pos_of_value_0_idx], current_config[current_pos_of_value_0_idx - 1]);
                strokes_applied.push_back(current_pos_of_value_0_idx);
                current_pos_of_value_0_idx--;
            }
        }

        std::cout << strokes_applied.size();
        for (int stroke_pos : strokes_applied)
        {
            std::cout << " " << stroke_pos;
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve_p_networks();
    return 0;
}