#include <bit>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr int MAX_N = 20;
constexpr std::size_t MAX_MASK = 1u << MAX_N;

static std::vector<int> dp(MAX_MASK, -1);
static std::uint32_t adjacency[MAX_N];
static int n;

int maxPairs(std::uint32_t mask) {
    if (mask == 0u || std::has_single_bit(mask)) {
        return 0;
    }
    int &memo = dp[mask];
    if (memo >= 0) {
        return memo;
    }

    int first = std::countr_zero(mask);
    std::uint32_t remaining = mask & ~(1u << first);
    int best = maxPairs(remaining);

    for (int j = first + 1; j < n; ++j) {
        if ((remaining & (1u << j)) && (adjacency[first] & (1u << j))) {
            int candidate = 2 + maxPairs(remaining & ~(1u << j));
            if (candidate > best) {
                best = candidate;
            }
        }
    }
    memo = best;
    return best;
}

int main() {
    int m;
    if (!(std::cin >> n >> m)) { return 0; }

    while (m--) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        adjacency[u] |= 1u << v;
        adjacency[v] |= 1u << u;
    }

    int matched = maxPairs((1u << n) - 1u);
    int answer  = matched;
    if (matched < n) { ++answer; }
    std::cout << answer << '\n';
    return 0;
}

