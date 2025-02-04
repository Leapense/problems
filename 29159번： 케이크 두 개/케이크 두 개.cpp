#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

pair<ll, ll> reduceFraction(ll num, ll den)
{
    if (den < 0)
    {
        num = -num;
        den = -den;
    }

    ll g = gcd(num, den);
    if (g == 0)
    {
        return {0, 1};
    }

    num /= g;
    den /= g;
    return {num, den};
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    ll s1x = 0, s1y = 0;
    vector<pair<ll, ll>> cake1(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> cake1[i].first >> cake1[i].second;
        s1x += cake1[i].first;
        s1y += cake1[i].second;
    }

    ll s2x = 0, s2y = 0;
    vector<pair<ll, ll>> cake2(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> cake2[i].first >> cake2[i].second;
        s2x += cake2[i].first;
        s2y += cake2[i].second;
    }

    ll dy = s2y - s1y;
    ll dx = s2x - s1x;
    auto pFrac = reduceFraction(dy, dx);

    ll num_q = s1y * pFrac.second - pFrac.first * s1x;
    ll den_q = 4 * pFrac.second;
    auto qFrac = reduceFraction(num_q, den_q);

    auto printFrac = [&](pair<ll, ll> frac)
    {
        if (frac.second == 1)
            cout << frac.first;
        else
            cout << frac.first << "/" << frac.second;
    };

    printFrac(pFrac);
    cout << " ";
    printFrac(qFrac);
    cout << "\n";

    return 0;
}