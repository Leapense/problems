#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace {
    constexpr int kMaxParty {26};

    struct Party {
        int count {};
        int index {};
    };

    [[nodiscard]]
    auto has_majority(const std::array<int, kMaxParty>& remain, int n, int total) -> bool {
        for (int i = 0; i < n; ++i) {
            if (remain[i] > total / 2) {
                return true;
            }
        }

        return false;
    }
}

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T {};
    if (!(std::cin >> T)) {
        return 0;
    }

    for (int tc = 1; tc <= T; ++tc) {
        int N {};
        std::cin >> N;
        std::array<int, kMaxParty> remain {};
        int total = 0;
        for (int i = 0; i < N; ++i) {
            std::cin >> remain[i];
            total += remain[i];
        }

        std::vector<std::string> plan;
        plan.reserve(2000);

        while (total > 0) {
            std::array<Party, kMaxParty> list {};
            for (int i = 0; i < N; ++i) {
                list[i] = Party{remain[i], i};
            }
            std::ranges::sort(list.begin(), list.begin() + N, [](const Party& a, const Party& b) {
                return a.count > b.count;
            });

            std::string step;
            step.push_back(static_cast<char>('A' + list[0].index));
            --remain[list[0].index];
            --total;

            if (total > 0 && has_majority(remain, N, total)) {
                step.push_back(static_cast<char>('A' + list[1].index));
                --remain[list[1].index];
                --total;
            }

            plan.emplace_back(std::move(step));
        }

        std::cout << "Case #" << tc << ':';
        for (const auto& s : plan) {
            std::cout << ' ' << s;
        }

        std::cout << '\n';
    }

    return 0;
}