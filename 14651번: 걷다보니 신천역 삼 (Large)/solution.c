#include <stdio.h>

#define MOD 1000000009

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }

        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    long long result = power(3, n - 2);
    result = (2 * result) % MOD;

    printf("%lld\n", result);
    return 0;
}