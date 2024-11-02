#include <iostream>
#include <limits>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    long long min_cost = std::numeric_limits<long long>::max();  // Using long long to handle potential overflows
    
    int best_index = 0;

    for (int i = 1; i <= N; i++) {
        long long P, K, C;
        std::cin >> P >> K >> C;
        long long cnt = (Q - 1) / K;

        long long val = P + cnt * (cnt + 1) / 2 * C;
        if (val < min_cost) {
            min_cost = val;
            best_index = i;
        }
    }

    std::cout << best_index << " " << min_cost << std::endl;

    return 0;
}
