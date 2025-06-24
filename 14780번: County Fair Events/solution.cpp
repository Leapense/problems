#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    long long start_time;
    long long end_time;
};

int max_events(std::vector<Event>& events) {
    std::ranges::sort(events, [](const Event& a, const Event& b) {
        if (a.end_time != b.end_time) {
            return a.end_time < b.end_time;
        }
        return a.start_time < b.start_time;
    });

    int count = 0;
    long long last_end_time = -1;

    for (const auto& event : events) {
        if (event.start_time >= last_end_time) {
            count++;
            last_end_time =  event.end_time;
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Event> events(n);

    for (auto& event : events) {
        long long t, l;
        std::cin >> t >> l;
        event.start_time = t;
        event.end_time = t + l;
    }

    std::cout << max_events(events) << "\n";
    return 0;
}