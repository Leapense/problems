#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int n1, n2;
    if (scanf("%d %d", &n1, &n2) != 2) {
        return 1;
    }
    int64_t k = (int64_t)n2 - n1 + 1;
    int64_t result = k * (k - 1) / 2;
    printf("%" PRId64 "\n", result);
    return 0;
}