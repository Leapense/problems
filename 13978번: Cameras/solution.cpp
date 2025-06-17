#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100'000;
static bool hasCam[MAX_N + 1];

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, k{}, r{};
    if (!(cin >> n >> k >> r)) {
        return 0;
    }

    for (int i = 0; i < k; ++i) {
        int pos{};
        cin >> pos;
        hasCam[pos] = true;
    }

    int camCnt = ranges::count_if(
        views::iota(1, r + 1),
        [](int idx) { return hasCam[idx]; }
    );

    int answer = 0;

    for (int left = 1; left <= n - r + 1; ++left) {
        const int right = left + r - 1;
        for (int pos = right; camCnt < 2 && pos >= left; --pos) {
            if (!hasCam[pos]) {
                hasCam[pos] = true;
                ++camCnt;
                ++answer;
            }
        }

        camCnt -= static_cast<int>(hasCam[left]);
        if (right + 1 <= n) {
            camCnt += static_cast<int>(hasCam[right + 1]);
        }
    }

    cout << answer << "\n";

    return 0;
}