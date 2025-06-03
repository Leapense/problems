#include <bits/stdc++.h>

namespace {
    constexpr int kMaxM = 1'000'000;

    std::array<bool, kMaxM + 1> buildSieve() {
        std::array<bool, kMaxM + 1> prime{};
        prime.fill(true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= kMaxM; ++p) {
            if (!prime[p]) {
                continue;
            }

            for (int multiple = p * p; multiple <= kMaxM; multiple += p) {
                prime[multiple] = false;
            }
        }
        return prime;
    }

    std::array<int, kMaxM + 1> buildPrevPrime(const std::array<bool, kMaxM + 1> &prime) {
        std::array<int, kMaxM + 1> prev{};
        int last = -1;
        for (int i = 0; i <= kMaxM; ++i) {
            if (prime[i]) {
                last = i;
            }

            prev[i] = last;
        }

        return prev;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const auto prime = buildSieve();
    const auto prev_prime = buildPrevPrime(prime);

    int tc{};
    std::cin >> tc;
    while (tc-- > 0) {
        int m{};
        std::cin >> m;
        int answer = prev_prime[m - 6];
        std::cout << answer << "\n";
    }

    return 0;
}