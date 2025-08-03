#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long count = 0;
    long long y_limit = static_cast<long long>(std::sqrt(b));

    for (long long y = 1; y <= y_limit; ++y) {
        long long z_min_area = (a + y - 1) / y;
        long long z_max_area = b / y;
        
        long long c_half = (c + 1) / 2;
        long long d_half = d / 2;

        long long z_min_perim = c_half > y ? c_half - y : 0;
        long long z_max_perim = d_half > y ? d_half - y : 0;

        long long z_lower = std::max({y, z_min_area, z_min_perim});
        long long z_upper = std::min(z_max_area, z_max_perim);

        if (z_lower <= z_upper) {
            count += (z_upper - z_lower + 1);
        }
    }

    std::cout << count << std::endl;

    return 0;
}