#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int main(void)
{
    int64_t p, q;
    int N, M;
    if (scanf("%" SCNd64 " %" SCNd64 " %d %d", &p, &q, &N, &M) != 4) {
        return EXIT_FAILURE;
    }

    for (int S = N; S <= M; ++S) {
        int64_t numerator = p * S * (S - 1);
        int64_t denom = 2 * q;
        if (numerator % denom != 0) {
            continue;
        }

        int64_t X = numerator / denom;
        int64_t D = (int64_t)S * S - 4 * X;
        if (D < 0) {
            continue;
        }
        int64_t sqrtD = (int64_t)(sqrt((long double)D) + 0.5L);
        if (sqrtD * sqrtD != D || ((S - sqrtD) & 1) != 0) {
            continue;
        }

        int64_t r = (S - sqrtD) / 2;
        int64_t g = (S - r);
        if (r >= 1 && r <= g) {
            printf("%" PRId64 " %" PRId64 "\n", r, g);
            return EXIT_SUCCESS;
        }
    }

    puts("NO SOLUTION");
    return EXIT_SUCCESS;
}