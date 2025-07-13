#include <iostream>
#include <vector>

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    std::vector<int> queries(T);
    int maxN = 0;
    for (auto &n : queries) {
        std::cin >> n;
        if (n > maxN) {
            maxN = n;
        }
    }

    int limit = 2 * maxN;
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int N : queries) {
        int target = 2 * N;
        for (int p = 2; p <= target / 2; ++p) {
            if (is_prime[p] && is_prime[target - p]) {
                std::cout << p << ' ' << (target - p) << '\n';
                break;
            }
        }
    }

    return 0;
}