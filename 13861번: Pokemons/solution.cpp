#include <iostream>
#include <algorithm>
#include <iomanip>

void solve() {
    double initial_money;
    if (!(std::cin >> initial_money)) return;

    int num_days;
    if (!(std::cin >> num_days)) return;

    if (num_days < 2) {
        std::cout << "0.00" << std::endl;
        return;
    }

    double min_price_so_far;
    std::cin >> min_price_so_far;

    double second_price;
    std::cin >> second_price;

    double max_ratio = second_price / min_price_so_far;
    min_price_so_far = std::min(min_price_so_far, second_price);

    for (int i = 2; i < num_days; ++i) {
        double current_price;
        std::cin >> current_price;
        max_ratio = std::max(max_ratio, current_price / min_price_so_far);
        min_price_so_far = std::min(min_price_so_far, current_price);
    }

    double max_profit = initial_money * (max_ratio - 1.0);
    std::cout << std::fixed << std::setprecision(2) << max_profit << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}