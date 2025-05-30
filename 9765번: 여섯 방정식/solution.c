#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

static uint64_t gcd_uint64(uint64_t a, uint64_t b)
{
    while (b != 0U)
    {
        uint64_t tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(void)
{
    uint64_t c1, c2, c3, c4, c5, c6;
    if (scanf("%" SCNu64 " %" SCNu64 " %" SCNu64 " %" SCNu64 " %" SCNu64 " %" SCNu64, &c1, &c2, &c3, &c4, &c5, &c6) != 6) {
        return 0;
    }

    // 공통 소수 추출
    const uint64_t x2 = gcd_uint64(c1, c5);
    const uint64_t x6 = gcd_uint64(c3, c6);

    // 나머지 소수 계산
    const uint64_t x1 = c1 / x2;
    const uint64_t x3 = c5 / x2;
    const uint64_t x7 = c3 / x6;
    const uint64_t x5 = c6 / x6;

    // 결과 출력
    printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", x1, x2, x3, x5, x6, x7);
    return 0;
}