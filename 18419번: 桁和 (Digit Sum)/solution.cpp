#include <iostream>
#include <vector>
#include <algorithm>

static constexpr int MAX_DIGIT_SUM = 54;

static int digit_sum(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }

    return s;
}

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    std::vector<char> visited(n + 1, 0);
    std::vector<int> q;
    q.reserve(n + 1);

    visited[n] = 1;
    q.push_back(n);

    for (std::size_t idx = 0; idx < q.size(); ++idx) {
        int cur = q[idx];
        int low = std::max(1, cur - MAX_DIGIT_SUM);
        for (int y = cur - 1; y >= low; --y) {
            if (!visited[y] && y + digit_sum(y) == cur) {
                visited[y] = 1;
                q.push_back(y);
            }
        }
    }

    int ans = static_cast<int>(std::count(visited.begin() + 1, visited.end(), 1));
    std::cout << ans << '\n';
    return 0;
}