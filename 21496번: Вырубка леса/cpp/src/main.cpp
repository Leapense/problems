#include <iostream>
#include "main.h"

using namespace std;

typedef __int128 int128;

long long solve(long long A, long long K, long long B, long long M, long long X)
{
    long long low = 1, high = X, ans = high;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long daysD = mid / K;
        long long daysF = mid / M;

        int128 treesD = (int128)A * (mid - daysD);
        int128 treesF = (int128)B * (mid - daysF);

        if (treesD + treesF >= X)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;

    cout << solve(A, K, B, M, X);

    return 0;
}
#endif