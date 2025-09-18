#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd_u64(unsigned long long a, unsigned long long b) {
    while (b) {
        unsigned long long t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main(void) {
    unsigned long long N, M;
    if (scanf("%llu %llu", &N, &M) != 2) return 0;

    unsigned long long g = gcd_u64(N, M);
    unsigned long long p = N / g;
    unsigned long long q = M / g;
    printf("%llu/%llu\n", p, q);
    return 0;
}