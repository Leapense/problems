#include <bit>
#include <cstdint>
#include <iostream>

namespace {
    [[nodiscard]] constexpr std::uint64_t sumHighestPowers(std::uint64_t n)
    {
        std::uint64_t acc = 0;
        for (std::uint64_t pow = 1; pow <= n; pow <<= 1U) {
            const std::uint64_t nextPow = pow << 1U;
            const std::uint64_t high = std::min<std::uint64_t>(n, nextPow - 1U);
            const std::uint64_t count = high - pow + 1U;
            acc += count * pow;
        }

        return acc;
    }
}

int main()
{
    std::uint64_t n;
    if (!(std::cin >> n)) { return 0; }

    const std::uint64_t total = n * (n + 1U) / 2U;
    const std::uint64_t sumPowers = sumHighestPowers(n);
    const std::uint64_t answer = total - sumPowers;

    std::cout << answer << "\n";
    return 0;
}