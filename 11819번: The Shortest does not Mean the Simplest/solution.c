#include <stdint.h>
#include <stdio.h>

static uint64_t modularPower(uint64_t base, uint64_t exponent, uint64_t modulus)
{
    uint64_t result = 1ULL;
    uint64_t curBase = base % modulus;

    while (exponent > 0U) {
        if ((exponent & 1ULL) != 0ULL) {
            __int128 temp = (__int128) result * curBase;
            result = (uint64_t)(temp % modulus);
        }

        __int128 square = (__int128)curBase * curBase;
        curBase = (uint64_t)(square % modulus);

        exponent >>= 1;
    }

    return result;
}

int main(void)
{
    uint64_t A = 0U;
    uint64_t B = 0U;
    uint64_t C = 0U;

    if (scanf("%llu %llu %llu", &A, &B, &C) != 3) {
        return 1;
    }

    uint64_t answer = modularPower(A, B, C);
    printf("%llu\n", answer);

    return 0;
}