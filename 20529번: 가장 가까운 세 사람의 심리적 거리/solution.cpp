#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

static int encode(const std::string& s) {
    int v = 0;
    v |= (s[0] == 'I') << 3;
    v |= (s[1] == 'N') << 2;
    v |= (s[2] == 'F') << 1;
    v |= (s[3] == 'P');
    return v;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;

    if (!(std::cin >> T)) return 0;
    std::array<std::array<int, 16>, 16> dist{};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            dist[i][j] = std::popcount(static_cast<unsigned>(i ^ j));
        }
    }

    while (T--) {
        int N;
        std::cin >> N;
        std::array<int, 16> cnt{};

        for (int i = 0; i < N; ++i) {
            std::string s;
            std::cin >> s;
            ++cnt[encode(s)];
        }

        int ans = 12;
        for (int i = 0; i < 16 && ans; ++i) {
            for (int j = i; j < 16 && ans; ++j) {
                for (int k = j; k < 16 && ans; ++k) {
                    if (i == j && j == k) {
                        if (cnt[i] < 3) continue;
                    } else if (i == j) {
                        if (cnt[i] < 2 || cnt[k] < 1) continue;
                    } else if (j == k) {
                        if (cnt[j] < 2 || cnt[i] < 1) continue;
                    } else {
                        if (cnt[i] < 1 || cnt[j] < 1 || cnt[k] < 1) continue;
                    }

                    int d = dist[i][j] + dist[j][k] + dist[i][k];
                    if (d < ans) ans = d;
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}