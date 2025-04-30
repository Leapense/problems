#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> solveOps(ll x, ll y)
{
    if (x == y)
    {
        return {0};
    }

    ll g = std::gcd(x, y);
    if (g > 1)
    {
        ll z = y - x;
        return {1, z};
    }
    else
    {
        ll m = x * y;
        ll z1 = m - x;
        ll z2 = m - y;
        return {2, z1, -z2};
    }
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;

    auto ops = solveOps(x, y);
    cout << ops[0] << "\n";

    for (size_t i = 1; i < ops.size(); i++)
    {
        cout << ops[i] << "\n";
    }

    return 0;
}
#endif