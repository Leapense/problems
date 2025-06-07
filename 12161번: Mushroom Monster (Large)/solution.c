#include <stdio.h>
#include <stdint.h>

static uint32_t calc_method1(const uint32_t *arr, size_t len) 
{
    uint32_t sum = 0;
    for (size_t i = 0U; i + 1U < len; ++i) {
        if (arr[i] > arr[i + 1U]) {
            sum += arr[i] - arr[i + 1U];
        }
    }

    return sum;
}

static uint32_t calc_method2(const uint32_t *arr, size_t len)
{
    uint32_t rate = 0;
    for (size_t i = 0U; i + 1U < len; ++i) {
        if (arr[i] > arr[i + 1U] && arr[i] - arr[i + 1U] > rate) {
            rate = arr[i] - arr[i + 1U];
        }
    }

    uint32_t sum = 0;
    for (size_t i = 0U; i + 1U < len; ++i) {
        sum += (arr[i] < rate) ? arr[i] : rate;
    }

    return sum;
}

int main()
{
    uint32_t t = 0U;
    if (scanf("%u", &t) != 1) {
        return 0;
    }

    for (uint32_t tc = 1U; tc <= t; ++tc) {
        size_t n = 0U;
        scanf("%zu", &n);
        uint32_t m[1000];
        for (size_t i = 0U; i < n; ++i) {
            scanf("%u", &m[i]);
        }

        const uint32_t y = calc_method1(m, n);
        const uint32_t z = calc_method2(m, n);
        printf("Case #%u: %u %u\n", tc, y, z);
    }

    return 0;
}