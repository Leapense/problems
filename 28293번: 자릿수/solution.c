#include <stdio.h>
#include <math.h>

int main(void)
{
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long double result = b * log10((long double)a);
    long long digits = (long long)floor(result) + 1;

    printf("%lld\n", digits);
    return 0;
}