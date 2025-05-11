#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

using State = std::array<int, 8>;

inline State opA_transform(const State &s)
{
    State next_s;
    next_s[0] = s[7];
    next_s[1] = s[6];
    next_s[2] = s[5];
    next_s[3] = s[4];
    next_s[4] = s[3];
    next_s[5] = s[2];
    next_s[6] = s[1];
    next_s[7] = s[0];
    return next_s;
}

inline State opB_transform(const State &s)
{
    State next_s;
    next_s[0] = s[3];
    next_s[1] = s[0];
    next_s[2] = s[1];
    next_s[3] = s[2];
    next_s[4] = s[5];
    next_s[5] = s[6];
    next_s[6] = s[7];
    next_s[7] = s[4];
    return next_s;
}

inline State opC_transform(const State &s)
{
    State next_s = s;
    next_s[1] = s[2];
    next_s[6] = s[1];
    next_s[5] = s[6];
    next_s[2] = s[5];
    return next_s;
}

inline State opD_transform(const State &s)
{
    State next_s = s;
    std::swap(next_s[0], next_s[4]);
    return next_s;
}

inline int find_minimum_operations(const State &target_state)
{
    State initial_state = {1, 2, 3, 4, 5, 6, 7, 8};

    if (initial_state == target_state)
    {
        return 0;
    }

    std::queue<std::pair<State, int>> q;
    std::map<State, int> visited_dist;

    q.push({initial_state, 0});
    visited_dist[initial_state] = 0;

    State (*transform_functions[])(const State &) = {
        opA_transform, opB_transform, opC_transform, opD_transform};

    while (!q.empty())
    {
        State current_s = q.front().first;
        int current_d = q.front().second;
        q.pop();

        for (auto &op_func : transform_functions)
        {
            State next_s = op_func(current_s);
            auto it = visited_dist.find(next_s);
            if (it == visited_dist.end())
            {
                if (next_s == target_state)
                {
                    return current_d + 1;
                }

                visited_dist[next_s] = current_d + 1;
                q.push({next_s, current_d + 1});
            }
        }
    }

    return -1;
}

inline State string_to_state(const std::string &s_str)
{
    State state;
    std::stringstream ss(s_str);
    for (int i = 0; i < 8; ++i)
    {
        ss >> state[i];
    }
    return state;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    State target_state_val;
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);

    for (int i = 0; i < 8; ++i)
    {
        ss >> target_state_val[i];
    }

    std::cout << find_minimum_operations(target_state_val) << std::endl;
    return 0;
}