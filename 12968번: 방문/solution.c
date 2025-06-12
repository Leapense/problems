#include <stdio.h>

int main(void)
{
    long long r, c, k;
    if (scanf("%lld %lld %lld", &r, &c, &k) != 3) {
        return 1;
    }

    int result;

    if (k == 1) {
        result = 1;
    } else {
        if ((r * c) % 2 == 0) {
            result = 1;
        } else {
            result = 0;
        }
    }

    printf("%d\n", result);

    return 0;
}