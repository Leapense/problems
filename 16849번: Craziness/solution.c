#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k;
    if (scanf("%d", &k) != 1) return EXIT_FAILURE;

    for (int tc = 1; tc <= k; ++tc)
    {
        int n;
        scanf("%d", &n);

        double a[20][20];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%lf", &a[i][j]);

        double best = -INFINITY;
        uint32_t limit = 1u << n;

        for (uint32_t m = 1u; m < limit; ++m)
        {
            double sum = 0.0;

            for (int i = 0; i < n; ++i)
                if (m & (1u << i))
                    sum += a[i][i];

            for (int i = 0; i < n; ++i)
                if (m & (1u << i))
                    for (int j = i + 1; j < n; ++j)
                        if (m & (1u << j))
                            sum += a[i][j];

            if (sum > best) best = sum;
        }

        if (fabs(best) < 0.005) best = 0.0;

        printf("Data Set %d:\n%.2f\n", tc, round(best * 100.0) / 100.0);
    }
    return EXIT_SUCCESS;
}