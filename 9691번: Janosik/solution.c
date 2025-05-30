#include <inttypes.h>
#include <stdio.h>

static uint64_t highest_power_of_two(uint64_t x) {
    // 반환값: x 이하 최대 2의 거듭제곱 (x >= 1)
    return 1ULL << (63 - __builtin_clzll(x));
}

int main(void)
{
    uint64_t n;
    if (scanf("%" SCNu64, &n) != 1) {
        return 0;
    }

    uint64_t sum_powers = 0;
    for (uint64_t pow = 1; pow <= n; pow <<= 1) {
        uint64_t next_pow = pow << 1;
        uint64_t high = (n < next_pow - 1) ? n : (next_pow - 1);
        uint64_t cnt = high - pow + 1;
        sum_powers += cnt * pow; 
    }

    uint64_t total = n * (n + 1) / 2;
    printf("%" PRIu64 "\n", total - sum_powers);
    return 0;
}