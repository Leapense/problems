#include <iostream>
#include <string>
using namespace std;
using ull = unsigned long long;
ull modmul(ull a, ull b, ull mod)
{
    ull result = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            result = (result + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return result;
}
ull modexp(ull base, ull exp, ull mod)
{
    ull result = 1;
    base %= mod;
    while (exp)
    {
        if (exp & 1)
            result = modmul(result, base, mod);
        base = modmul(base, base, mod);
        exp >>= 1;
    }
    return result;
}
bool isPrime(ull n)
{
    if (n < 2)
        return false;
    int smallPrimes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (int p : smallPrimes)
    {
        if (n == (ull)p)
            return true;
        if (n % p == 0)
            return false;
    }
    ull d = n - 1;
    int s = 0;
    while ((d & 1ULL) == 0)
    {
        d >>= 1;
        s++;
    }
    ull testPrimes[7] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (ull a : testPrimes)
    {
        if (a % n == 0)
            continue;
        ull x = modexp(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool cont = false;
        for (int r = 1; r < s; r++)
        {
            x = modmul(x, x, n);
            if (x == n - 1)
            {
                cont = true;
                break;
            }
        }
        if (!cont)
            return false;
    }
    return true;
}
ull reverseNumber(ull n, bool &valid)
{
    string s = to_string(n), rs;
    valid = true;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (c == '0')
            rs.push_back('0');
        else if (c == '1')
            rs.push_back('1');
        else if (c == '2')
            rs.push_back('2');
        else if (c == '5')
            rs.push_back('5');
        else if (c == '6')
            rs.push_back('9');
        else if (c == '8')
            rs.push_back('8');
        else if (c == '9')
            rs.push_back('6');
        else
        {
            valid = false;
            break;
        }
    }
    if (!valid)
        return 0;
    return stoull(rs);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull N;
    cin >> N;
    bool valid;
    ull R = reverseNumber(N, valid);
    if (valid && isPrime(N) && isPrime(R))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
