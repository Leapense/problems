#include <bits/stdc++.h>
using std::uint64_t;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    uint64_t c1, c2, c3, c4, c5, c6;
    if (!(std::cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6)) 
    {
        return 0;
    }

    const uint64_t x2 = std::gcd(c1, c5);
    const uint64_t x6 = std::gcd(c3, c6);

    const uint64_t x1 = c1 / x2;
    const uint64_t x3 = c5 / x2;
    const uint64_t x7 = c3 / x6;
    const uint64_t x5 = c6 / x6;

    std::cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x5 << ' ' << x6 << ' ' << x7 << '\n';

    return 0;
}