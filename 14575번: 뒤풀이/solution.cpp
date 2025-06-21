#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

namespace AfterPartySolver {
    bool can_distribute(long long s_candidate, int n, long long total_t, long long total_l, const std::vector<std::pair<int, int>>& ranges) {
        if (s_candidate < 0) {
            return false;
        }

        long long current_max_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s_candidate < ranges[i].first) {
                return false;
            }

            current_max_sum += std::min((long long)ranges[i].second, s_candidate);
        }

        return total_l <= total_t && total_t <= current_max_sum;
    }

    void solve() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int n;
        long long t;
        std::cin >> n >> t;

        std::vector<std::pair<int, int>> ranges(n);
        long long total_l = 0;
        long long total_r = 0;
        int max_l = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> ranges[i].first >> ranges[i].second;
            total_l += ranges[i].first;
            total_r += ranges[i].second;
            max_l = std::max(max_l, ranges[i].first);
        }

        if (t < total_l || t > total_r) {
            std::cout << -1 << "\n";
            return;
        }

        long long low = max_l;
        long long high = 1'000'000'000;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (can_distribute(mid, n, t, total_l, ranges)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        std::cout << ans << "\n";
    }
}

int main() {
    AfterPartySolver::solve();
    return 0;
}