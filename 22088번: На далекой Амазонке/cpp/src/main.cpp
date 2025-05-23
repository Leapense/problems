#include "main.h"

void solve()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n, a, b;
        std::cin >> n >> a >> b;

        if (b > n - 1 || a > b) {
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        std::vector<std::vector<int>> children(n + 1);

        if (a == 0 && b == 0) {
            for (int i = 1; i <= n; i++) {
                std::cout << 0 << "\n";
            }
            continue;
        }

        for (int i = 1; i <= a; i++) {
            children[i].push_back(i + 1);
        }

        int extra = b - a;
        for (int i = a + 2; i <= a + 1 + extra; i++) {
            children[1].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            std::cout << children[i].size();
            for (int child : children[i]) {
                std::cout << " " << child;
            }

            std::cout << "\n";
        }
    }
}

#ifndef UNIT_TESTS
int main()
{
    solve();
    return 0;
}
#endif
