#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

static bool find_smallest_base(int64_t n, int64_t* result)
{
    if (n < 3) {
        return false;
    }
    if (n == 3) {
        *result = 4;
        return true;
    }

    int64_t m = n - 3;
    if (m < 4) {
        return false;
    }

    if ((m % 4) == 0) 
    {
        *result = 4;
        return true;
    }

    for (int64_t d = 5; d * d <= m; ++d) {
       if ((m % d) == 0) {
            *result = d;
            return true;
        } 
    }

    int64_t best = m;
    if (((m % 2) == 0) && ((m / 2) >= 4)) {
        if ((m / 2) < best) {
            best = (m / 2);
        }
    }

    if (((m % 3) == 0) && ((m / 3) >= 4)) {
        if ((m / 3) < best) {
            best = (m / 3);
        }
    }

    *result = best;
    return true;
}

int main(void)
{
    int64_t n;

    while (true)
    {
        if (scanf("%" SCNd64, &n) != 1) {
            break;
        }

        if (n == 0) {
            break;
        }

        int64_t base = 0;
        bool ok = find_smallest_base(n, &base);

        if (ok) {
            printf("%" PRId64 "\n", base);
        } else {
            printf("No such base\n");
        }
    }

    return 0;
}
