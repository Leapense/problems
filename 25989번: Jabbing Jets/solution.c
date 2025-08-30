#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int n;
    double e;
    if (scanf("%d %lf", &n, &e) != 2) return 0;
    int ri;
    uint64_t ans = 0;
    const double PI = acos(-1.0);
    const double EPS = 1e-12;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &ri) != 1) return 0;
        double r = (double)ri;
        if (e > 2.0 * r + EPS) {
            ans += 1;
        } else if (fabs(e - 2.0 * r) <= EPS) {
            ans += 2;
        } else {
            double x = e / (2.0 * r);
            if (x < 0.0) x = 0.0;
            if (x > 1.0) x = 1.0;
            double alpha = 2.0 * asin(x);
            double k = (2.0  * PI) / alpha;
            uint64_t cnt = (uint64_t)floor(k + 1e-12);
            if (cnt < 1) cnt = 1;
            ans += cnt;
        }
    }
    printf("%" PRIu64 "\n", ans);
    return 0;
}