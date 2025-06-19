#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

constexpr int MAX_TYPE = 101;
constexpr int MAX_REACHABLE_TYPE = 202;

void solve() {
    int a, b;
    if (!(std::cin >> a >> b) || a == -1) {
        exit(0);
    }

    std::vector<int> countsA(MAX_TYPE, 0);
    std::vector<int> countsB(MAX_TYPE, 0);
    int type;

    for (int i = 0; i < a; ++i) {
        std::cin >> type;
        if (type < MAX_TYPE) countsA[type]++;
    }
    for (int i = 0; i < b; ++i) {
        std::cin >> type;
        if (type < MAX_TYPE) countsB[type]++;
    }

    // 1. 홀수 타입 개수의 '홀짝성' 비교
    for (int i = 1; i < MAX_TYPE; i += 2) {
        if ((countsA[i] % 2) != (countsB[i] % 2)) {
            std::cout << "N\n";
            return;
        }
    }

    // 2. 도달 가능한 짝수 타입 집합 비교
    auto get_reachable_evens = [](const std::vector<int>& counts) {
        std::unordered_set<int> reachable;
        for (int i = 0; i < MAX_TYPE; ++i) {
            if (counts[i] > 0) {
                if (i % 2 == 0) {
                    reachable.insert(i);
                } else {
                    if (2 * i + 2 < MAX_REACHABLE_TYPE) {
                        reachable.insert(2 * i + 2);
                    }
                }
            }
        }
        return reachable;
    };

    if (get_reachable_evens(countsA) != get_reachable_evens(countsB)) {
        std::cout << "N\n";
        return;
    }

    std::cout << "Y\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (true) {
        solve();
    }
    return 0;
}