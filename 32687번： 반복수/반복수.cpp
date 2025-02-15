#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll ipow10(int exp)
{
    ll res = 1;
    while (exp--)
        res *= 10;
    return res;
}

int digitCount(ll x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, M;
    int K;
    cin >> A >> B >> K >> M;

    int D = digitCount(B);

    ll lowX = ipow10(K - 1);
    ll highX = ipow10(K) - 1;

    ll ans = 0;

    for (int L = K; L <= D; L++)
    {
        int q = L / K;
        int r = L % K;

        ll numerator = ipow10(q * K) - 1;
        ll denominator = ipow10(K) - 1;
        ll F = numerator / denominator;

        ll pow10r = ipow10(r);

        for (ll X = lowX; X <= highX; X++)
        {
            ll candidate;
            if (r == 0)
            {
                candidate = X * F;
            }
            else
            {
                candidate = (X * F) * pow10r + (X / ipow10(K - r));
            }

            if (candidate < A || candidate > B)
                continue;
            if (candidate % M == 0)
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}