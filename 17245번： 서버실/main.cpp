#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using ll = long long;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    ll total = 0;
    int maxHeight = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> grid[i][j];
            total += grid[i][j];
            maxHeight = std::max(maxHeight, grid[i][j]);
        }
    }

    ll required = (total + 1) / 2;

    int lo = 0, hi = maxHeight;
    int ans = hi;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        ll cooled = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cooled += std::min(mid, grid[i][j]);
            }
        }

        if (cooled >= required)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}