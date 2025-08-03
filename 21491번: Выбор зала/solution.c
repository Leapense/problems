#include <stdio.h>
#include <math.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long a, b, c, d;
    if (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != 4) {
        return 1;
    }

    long long count = 0;
    long long y_limit = sqrt(b);

    for (long long y = 1; y <= y_limit; ++y) {
        long long z_min_area = (a + y - 1) / y;
        long long z_max_area = b / y;

        long long c_half = (c + 1) / 2;
        long long d_half = d / 2;

        long long z_min_perim = c_half - y;
        long long z_max_perim = d_half - y;

        long long z_lower = max(y, max(z_min_area, z_min_perim));
        long long z_upper = min(z_max_area, z_max_perim);

        if (z_lower <= z_upper) {
            count += (z_upper - z_lower + 1);
        }
    }

    printf("%lld\n", count);

    return 0;
}
