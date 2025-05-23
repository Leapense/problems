#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R, G;
    cin >> R >> G;

    long long g = gcd(R, G);

    vector<long long> divisors;
    for (long long i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            divisors.push_back(i);
            if (i != g / i)
            {
                divisors.push_back(g / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    for (long long d : divisors)
    {
        cout << d << " " << R / d << " " << G / d << "\n";
    }

    return 0;
}