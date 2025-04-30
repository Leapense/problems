#include <bits/stdc++.h>
using namespace std;

static long long gcdll(long long a, long long b)
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static long long smallest_prime_factor(long long n)
{
    if (n % 2 == 0)
        return 2;
    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }

    return n;
}

vector<long long> getOperations(long long x, long long y)
{
    if (x == y)
    {
        return {};
    }

    long long g = gcdll(x, y);
    long long dz = y - x;

    if (g > 1)
    {
        return {dz};
    }

    long long p = smallest_prime_factor(y);
    long long rem = x % p;
    long long z1 = (p - rem) % p;

    if (z1 == 0)
        z1 = p;
    long long x1 = x + z1;
    long long z2 = y - x1;
    return {z1, z2};
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    if (!(cin >> x >> y))
        return 0;

    auto ops = getOperations(x, y);
    cout << ops.size() << "\n";

    for (auto z : ops)
    {
        cout << z << "\n";
    }

    return 0;
}
#endif