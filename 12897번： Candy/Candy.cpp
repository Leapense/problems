#include <iostream>
using namespace std;
constexpr long long MOD = 1000000007;

long long modExp(long long base, int exp)
{
    long long result = 1;
    while (exp)
    {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long ans = (modExp(3, N) - 1 + MOD) % MOD;
    cout << ans;

    return 0;
}