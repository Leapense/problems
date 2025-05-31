#include <iostream>
#include <cstdint>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != -1) {
        uint64_t a = 1, b = 1;
        for (int i = 2; i <= n; ++i) {
            auto [pa, pb] = std::pair{a, b};
            a = pa + 2 * pb;
            b = 2 * pa + 2 * pb;
        }

        uint64_t S = 2 * (a + b);

        uint64_t pow4 = 1, pow2 = 1;
        for (int i = 0; i < n; ++i) {
            pow4 *= 4;
            pow2 <<= 1;
        }

        uint64_t answer = pow4 - S - pow2 + 2;
        std::cout << n << ": " << answer << "\n";
    }

    return 0;
}