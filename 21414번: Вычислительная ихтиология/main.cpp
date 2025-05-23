#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

int time_to_next_birth(int population_size)
{
    return std::max(1, 1000 - population_size);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> current_sizes(n);

    std::priority_queue<
        std::pair<long long, int>,
        std::vector<std::pair<long long, int>>,
        std::greater<std::pair<long long, int>>>
        birth_events_pq;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> current_sizes[i];
        long long first_birth_time = time_to_next_birth(current_sizes[i]);
        birth_events_pq.push({first_birth_time, i});
    }

    long long current_time = 0;
    int current_aquarium_index = 0;
    long long first_missed_time = -1;

    while (!birth_events_pq.empty())
    {
        std::pair<long long, int> next_event = birth_events_pq.top();
        birth_events_pq.pop();

        long long birth_time = next_event.first;
        int target_index = next_event.second;

        int travel_time = std::abs(target_index - current_aquarium_index);

        if (current_time + travel_time <= birth_time)
        {
            current_time = birth_time;
            current_aquarium_index = target_index;

            current_sizes[target_index]++;
            int time_delta = time_to_next_birth(current_sizes[target_index]);
            long long new_next_birth_time = current_time + time_delta;
            birth_events_pq.push({new_next_birth_time, target_index});
        }
        else
        {
            first_missed_time = birth_time;
            break;
        }
    }

    std::cout << first_missed_time << std::endl;

    return 0;
}