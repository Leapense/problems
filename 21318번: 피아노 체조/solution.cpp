#include <iostream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    std::vector<long long> score(n);
    for (auto &v : score) {
        std::cin >> v;
    }
    std::vector<int> pref(n);
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + (score[i - 1] > score[i]);
    }

    int q;
    std::cin >> q;
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << pref[y - 1] - pref[x - 1] << "\n";
    }

    return 0;
}