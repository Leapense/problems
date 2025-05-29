#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int temp{0};
    int delta_milk{0};

    bool operator<(const Event& other) const noexcept {
        if (temp != other.temp) {
            return temp < other.temp;
        }

        return false;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_cows;
    int x_milk, y_milk, z_milk;

    if (!(std::cin >> n_cows >> x_milk >> y_milk >> z_milk)) {
        return 1;
    }

    std::vector<Event> events;
    events.reserve(static_cast<size_t>(n_cows) * 2);

    for (int i = 0; i < n_cows; ++i) {
        int a_temp, b_temp;
        if (!(std::cin >> a_temp >> b_temp)) {
            return 1;
        }
        events.push_back({a_temp, y_milk - x_milk});
        events.push_back({b_temp + 1, z_milk - y_milk});
    }

    std::sort(events.begin(), events.end(), [](const Event& lhs, const Event& rhs) {
        if (lhs.temp != rhs.temp) {
            return lhs.temp < rhs.temp;
        }
        return false;
    });

    long long current_total_milk = static_cast<long long>(n_cows) * x_milk;
    long long max_total_milk = current_total_milk;

    size_t i = 0;
    while (i < events.size()) {
        int current_event_temp = events[i].temp;
        size_t j = i;
        while (j < events.size() && events[j].temp == current_event_temp) {
            current_total_milk += events[j].delta_milk;
            j++;
        }

        if (current_total_milk > max_total_milk) {
            max_total_milk = current_total_milk;
        }
        i = j;
    }

    std::cout << max_total_milk << std::endl;
    return 0;
}