#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *lhs, const void *rhs)
{
    int x = *(const int *)lhs;
    int y = *(const int *)rhs;
    return x - y;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }

    int *a = malloc(sizeof(int) * (size_t)n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, (size_t)n, sizeof(int), cmp_int);

    long long revenue = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        revenue += 2LL * a[j];
        ++i;
        --j;
    }

    if (i == j) {
        revenue += a[i];
    }

    printf("%lld\n", revenue);
    free(a);
    return 0;
}