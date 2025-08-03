#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 64

int main(void)
{
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) {
        return 0;
    }

    int d = n - 1;
    long long a[MAX_SEGMENTS];
    int m = 0;

    for (int i = 0; i < d; i++) {
        a[m++] = 1;
    }
    while(1) {
        long long sum = 0;
        for (int j = m - d; j < m; j++) {
            sum += a[j];
        }
        if (sum > k) {
            break;
        }
        a[m++] = sum;
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%lld", a[i]);
        if (i + 1 < m) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}