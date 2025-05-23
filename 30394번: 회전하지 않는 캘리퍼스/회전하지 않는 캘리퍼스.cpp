#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, i;
    int mx = -2e9;
    int mn = 2e9;
    int x, y;

    std::cin >> N;

    for (i = 0; i < N; i++) {
        std::cin >> x >> y;
        mx = std::max(mx, y);
        mn = std::min(mn, y);
    }

    std::cout << mx - mn << "\n";

    return 0;
}
