#include <cstdint>
#include <iostream>
#include <vector>

namespace {
bool hasAxis(const std::vector<int> &v) {
    const int n = static_cast<int>(v.size());
    if (n % 2 == 0) {
        const int h = n / 2;
        for (int c = 0; c < h; ++c) {
            bool ok = true;
            for (int d = 1; d < h && ok; ++d) {
                if (v[(c + d) % n] != v[(c - d + n) % n]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        for (int c = 0; c < h; ++c) {
            bool ok = true;
            for (int d = 0; d < h && ok; ++d) {
                if (v[(c - d + n) % n] != v[(c + 1 + d) % n]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
    } else {
        const int h = n / 2;
        for (int c = 0; c < n; ++c) {
            bool ok = true;
            for (int d = 1; d <= h && ok; ++d) {
                if (v[(c + d) % n] != v[(c - d + n) % n]) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
    }
    return false;
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    if (n <= 5) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::vector<int> beads(n);
    const int base[6] = {0, 0, 1, 0, 1, 1};
    for (int i = 0; i < n; ++i) {
        beads[i] = base[i % 6];
    }
    if (hasAxis(beads)) {
        std::uint32_t seed = 1;
        while (true) {
            std::uint32_t x = seed++;
            for (int i = 0; i < n; ++i) {
                x = x * 1103515245u + 12345u;
                beads[i] = static_cast<int>((x >> 31) & 1u);
            }
            if (!hasAxis(beads)) {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << beads[i];
    }
    std::cout << '\n';
    return 0;
}