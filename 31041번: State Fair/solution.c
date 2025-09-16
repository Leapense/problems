#include <stdio.h>
#include <math.h>

int main(void)
{
    int tc;
    if (scanf("%d", &tc) != 1) return 0;
    for (int _ = 0; _ < tc; ++_) {
        double r, c;
        scanf("%lf %lf", &r, &c);
        double denom = 2.0 * (c * c - 4.0 * r * r);
        double s = (c * (c * c + 4.0 * r * r)) / denom;
        printf("%.3f\n", s + 1e-12);
    }

    return 0;
}