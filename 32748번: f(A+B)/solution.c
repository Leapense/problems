#include <stdio.h>
#include <stdint.h>

int main(void) {
    int f[10];
    int f_inv[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &f[i]);
        f_inv[f[i]] = i;
    }

    int64_t f_a, f_b;
    scanf("%ld %ld", &f_a, &f_b);

    int a_digits[8] = {0};
    int b_digits[8] = {0};
    int a_len = 0, b_len = 0;

    while (f_a > 0) {
        a_digits[a_len++] = f_inv[f_a % 10];
        f_a /= 10;
    }

    while (f_b > 0) {
        b_digits[b_len++] = f_inv[f_b % 10];
        f_b /= 10;
    }

    int64_t a = 0, b = 0;
    for (int i = a_len - 1; i >= 0; --i) {
        a = a * 10 + a_digits[i];
    }
    for (int i = b_len - 1; i >= 0; --i) {
        b = b * 10 + b_digits[i];
    }

    int64_t sum = a + b;
    int sum_digits[8] = {0};
    int sum_len = 0;
    while (sum > 0) {
        sum_digits[sum_len++] = f[sum % 10];
        sum /= 10;
    }

    int64_t result = 0;
    for (int i = sum_len - 1; i >= 0; --i) {
        result = result * 10 + sum_digits[i];
    }

    printf("%ld\n", result);
    return 0;
}