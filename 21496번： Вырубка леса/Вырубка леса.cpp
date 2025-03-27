#include <iostream>
using namespace std;

using int128 = __int128;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;

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

    cout << ans;

    return 0;
}