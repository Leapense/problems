#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    std::cin >> x >> y;

    int r_max = (2 * x + 3 * y) / 100;
    int ans = 0;

    for (int r = 0; r <= r_max; r++)
    {
        int S_lower = std::max(0, (int)ceil((50.0 * r - x) / 3.0));
        int S_upper = std::min(16 * r, y / 2);

        if (S_lower <= S_upper)
            ans = r;
    }

    std::cout << ans;
    return 0;
}