#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Snack {
    int fullness;
    int satisfaction;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int m;
    std::cin >> n >> m;

    std::vector<Snack> snacks(n);
    int max_fullness_per_snack = 0;
    for (auto& snack : snacks) {
        std::cin >> snack.fullness >> snack.satisfaction;
        if (snack.fullness > max_fullness_per_snack) {
            max_fullness_per_snack = snack.fullness;
        }
    }

    const int dp_size = m + max_fullness_per_snack;
    const int infinity = std::numeric_limits<int>::max();
    std::vector<int> dp(dp_size, infinity);
    dp[0] = 0;

    for (const auto& snack : snacks) {
        for (int j = dp_size - 1; j >= snack.fullness; --j) {
            if (dp[j - snack.fullness] != infinity) {
                dp[j] = std::min(dp[j], dp[j - snack.fullness] + snack.satisfaction);
            }
        }
    }

    int min_satisfaction = infinity;
    for (int i = m; i < dp_size; ++i) {
        min_satisfaction = std::min(min_satisfaction, dp[i]);
    }

    if (min_satisfaction == infinity) {
        std::cout << "죄송합니다 한승엽 병장님\n";
    } else {
        std::cout << min_satisfaction << "\n";
    }

    return 0;
}