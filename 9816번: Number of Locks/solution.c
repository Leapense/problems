#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1 && n != -1) {
        uint64_t a = 1, b = 1;
        for (int i = 2; i <= n; ++i) {
            uint64_t prevA = a;
            uint64_t prevB = b;
            a = prevA + 2 * prevB;
            b = 2 * prevA + 2 * prevB;
        }
        uint64_t S = 2 * (a + b);

        uint64_t pow4 = 1;
        for (int i = 0; i < n; ++i)
        {
            pow4 *= 4;
        }

        uint64_t pow2 = 1;
        for (int i = 0; i < n; ++i) {
            pow2 *= 2;
        }

        uint64_t result = pow4 - S - pow2 + 2;
        printf("%d: %" PRIu64 "\n", n, result);
    }

    return 0;
}