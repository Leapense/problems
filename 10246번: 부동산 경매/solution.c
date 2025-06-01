#include <stdio.h>
#include <stdlib.h>

static long long countConsecutiveAuctionWays(long long N)
{
    long long M = 2LL * N;
    long long limit = 0;
    long long count = 0;

    for (long long d = 1; d * d <= M; ++d)
    {
        if (M % d == 0)
        {
            long long numerator = (M / d) - (d + 1);
            if ((numerator % 2LL) == 0) {
                long long i = numerator / 2LL;
                if (i >= 1LL) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main(void)
{
    while (1)
    {
        long long N = 0LL;
        if (scanf("%lld", &N) != 1) {
            return 0;
        }

        if (N == 0LL) {
            break;
        }

        long long result = countConsecutiveAuctionWays(N);
        printf("%lld\n", result);
    }

    return 0;
}