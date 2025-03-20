#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using ll = long long;

ll convert(const std::string &s, int base)
{
    ll res = 0;
    for (char c : s)
    {
        res = res * base + (c - '0');
    }

    return res;
}

ll findDivisor(ll num)
{
    for (ll d = 2; d * d <= num && d < 10000; d++)
    {
        if (num % d == 0)
            return d;
    }

    return 0;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, N, J;
    std::cin >> T >> N >> J;
    std::cout << "Case #1:" << "\n";

    int found = 0;

    for (int i = 0; i < (1 << (N - 2)) && found < J; i++)
    {
        std::string coin = "1";
        for (int j = N - 3; j >= 0; j--)
        {
            coin.push_back(((i >> j) & 1) ? '1' : '0');
        }
        coin.push_back('1');
        std::vector<ll> divisors;

        bool valid = true;

        for (int base = 2; base <= 10; base++)
        {
            ll val = convert(coin, base);
            ll divisor = findDivisor(val);
            if (divisor == 0)
            {
                valid = false;
                break;
            }

            divisors.push_back(divisor);
        }

        if (valid)
        {
            std::cout << coin;
            for (ll d : divisors)
                std::cout << " " << d;
            std::cout << "\n";
            found++;
        }
    }

    return 0;
}