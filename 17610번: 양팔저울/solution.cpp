#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <cmath>
#include <algorithm>

void solve() {
    int k;
    std::cin >> k;
    std::vector<int> weights(k);
    long long total_sum = 0;
    for (int i = 0; i < k; ++i) {
        std::cin >> weights[i];
        total_sum += weights[i];
    }

    std::unordered_set<int> possible_sums = {0};

    for (int weight : weights) {
        std::unordered_set<int> next_sums = possible_sums;
        for (int s : possible_sums) {
            next_sums.insert(s + weight);
            next_sums.insert(s - weight);
        }
        possible_sums = std::move(next_sums);
    }

    std::vector<bool> measurable(total_sum + 1, false);
    int measurable_count = 0;

    for (int s : possible_sums) {
        int positive_s = std::abs(s);
        if (positive_s > 0 && positive_s <= total_sum) {
            if (!measurable[positive_s]) {
                measurable[positive_s] = true;
                measurable_count++;
            }
        }
    }

    std::cout << total_sum - measurable_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}