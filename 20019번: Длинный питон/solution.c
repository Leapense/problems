#include <stdio.h>

int main(void)
{
    long long parrotCount, monkeyCount;
    scanf("%lld", &parrotCount);
    scanf("%lld", &monkeyCount);

    long long minParrots = parrotCount / (monkeyCount + 1);
    long long maxParrots = parrotCount / monkeyCount;

    printf("%lld\n", minParrots);
    printf("%lld\n", maxParrots);

    return 0;
}