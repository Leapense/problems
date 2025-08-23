#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

void setup_fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_fast_io();

    int n;
    std::cin >> n;
    std::vector<std::pair<char, int>> statements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> statements[i].first >> statements[i].second;
    }

    int min_liars = n;
    for (int i = 0; i < n; ++i) {
        int candidate_location = statements[i].second;
        int current_liars = 0;
        for (int j = 0; j < n; ++j) {
            if (statements[j].first == 'G') {
                if (candidate_location < statements[j].second) {
                    current_liars++;
                }
            } else {
                if (candidate_location > statements[j].second) {
                    current_liars++;
                }
            }
        }

        min_liars = std::min(min_liars, current_liars);
    }

    std::cout << min_liars << std::endl;

    return 0;
}