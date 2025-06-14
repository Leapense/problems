#include <array>
#include <cstdint>
#include <iostream>

namespace {
    using Table = std::array<std::array<int, 10>, 10>;
    using Digits = std::array<int, 5>;

    constexpr int kTableSize = 10;

    [[nodiscard]]
    int check_function(const Table& t, const Digits& d) noexcept
    {
        int state = 0;
        for (int i = 0; i < 5; ++i) {
            state = t[state][d[i]];
        }

        return state;
    }

    [[nodiscard]]
    int compute_check_digit(const Table& t, int a, int b, int c, int d) noexcept
    {
        int state = 0;
        state = t[state][a];
        state = t[state][b];
        state = t[state][c];
        state = t[state][d];
        return state;
    }

    [[nodiscard]]
    bool has_undetected_error(const Table& t, int a, int b, int c, int d) noexcept
    {
        const int e = compute_check_digit(t, a, b, c, d);
        Digits digits {a, b, c, d, e};

        for (int pos = 0; pos < 5; ++pos) {
            const int original = digits[pos];
            for (int repl = 0; repl < kTableSize; ++repl) {
                if (repl == original) {
                    continue;
                }
                digits[pos] = repl;
                if (check_function(t, digits) == 0) {
                    return true;
                }
            }
            digits[pos] = original;
        }

        for (int pos = 0; pos < 4; ++pos) {
            if (digits[pos] == digits[pos + 1]) {
                continue;
            }
            std::swap(digits[pos], digits[pos + 1]);
            if (check_function(t, digits) == 0) {
                return true;
            }
            std::swap(digits[pos], digits[pos + 1]);
        }

        return false;
    }
}

int main()
{
    Table table{};
    for (auto& row : table) {
        for (int& cell : row) {
            std::cin >> cell;
        }
    }

    std::uint32_t bad_count = 0;
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                for (int d = 0; d < 10; ++d) {
                    if (has_undetected_error(table, a, b, c, d)) {
                        ++bad_count;
                    }
                }
            }
        }
    }

    std::cout << bad_count << "\n";
    return 0;
}