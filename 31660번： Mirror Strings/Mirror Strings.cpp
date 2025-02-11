#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, R;
    cin >> L >> R;

    int maxK = (R + 1) / 2;
    vector<long long> pow5(maxK + 1, 0), pow2(maxK + 1, 0);

    pow5[0] = 1;
    pow2[0] = 1;

    for (int i = 1; i <= maxK; i++)
    {
        pow5[i] = (pow5[i - 1] * 5LL) % MOD;
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    }

    long long ans = 0;

    for (int m = L; m <= R; m++)
    {
        int k = (m + 1) / 2;
        long long cur = (pow5[k] + pow2[k]) % MOD;
        ans = (ans + cur) % MOD;
    }

    cout << ans % MOD << "\n";

    return 0;
}