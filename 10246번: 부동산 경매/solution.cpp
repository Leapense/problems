#include <bits/stdc++.h>
using namespace std;

static long long countWays(long long N)
{
    long long M = 2LL * N;
    long long cnt = 0;
    long long limit = static_cast<long long> (std::floor(std::sqrt(static_cast<long double>(M))));

    for (long long d = 1; d <= limit; ++d) {
        if (M % d == 0) {
            long long numerator = (M / d) - (d + 1);
            if ((numerator % 2LL) == 0) {
                long long i = numerator / 2LL;
                if (i >= 1) {
                    ++cnt;
                }
            }

            long long d2 = M / d;
            if (d2 != d) {
                long long numerator2 = (M / d2) - (d2 + 1);
                if ((numerator2 % 2LL) == 0) {
                    long long i2 = numerator2 / 2LL;
                    if (i2 >= 1) {
                        ++cnt;
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        long long N;
        if (!(cin >> N)) {
            return 0;
        }

        if (N == 0LL) {
            break;
        }

        long long result = countWays(N);
        cout << result << "\n";
    }

    return 0;
}