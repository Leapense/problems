#include <iostream>
#include <numeric>
#include <map>

using namespace std;

struct Fraction
{
    __int128 num, den;
};

__int128 gcd128(__int128 a, __int128 b)
{
    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

Fraction reduce(Fraction f)
{
    if (f.num == 0)
    {
        return {0, 1};
    }
    __int128 g = gcd128((f.num < 0) ? -f.num : f.num, f.den);
    f.num /= g;
    f.den /= g;
    return f;
}

Fraction make_fraction(__int128 num, __int128 den)
{
    Fraction f{num, den};
    return reduce(f);
}

Fraction add(const Fraction &a, const Fraction &b)
{
    Fraction res;
    res.num = a.num * b.den + b.num * a.den;
    res.den = a.den * b.den;
    return reduce(res);
}

Fraction multiply(const Fraction &a, const Fraction &b)
{
    Fraction res;
    res.num = a.num * b.num;
    res.den = a.den * b.den;
    return reduce(res);
}

map<pair<int, int>, Fraction> dp;

Fraction solve(int n, int m)
{
    if (dp.count({n, m}))
        return dp[{n, m}];
    if (m == 0)
        return dp[{n, m}] = make_fraction(1, 1);
    if (m == 1)
        return dp[{n, m}] = make_fraction(n, n + 1);

    Fraction term1 = make_fraction(n, n + m);
    Fraction term2 = multiply(make_fraction(m, n + m), make_fraction(m - 1, n + m - 1));
    Fraction rec = solve(n, m - 2);
    Fraction term2full = multiply(term2, rec);
    Fraction ans = add(term1, term2full);
    dp[{n, m}] = ans;
    return ans;
}

void printFraction(const Fraction &f)
{
    auto toString = [&](__int128 x) -> string
    {
        if (x == 0)
            return "0";
        string s;
        bool neg = x < 0;
        if (neg)
            x = -x;
        while (x > 0)
        {
            s.push_back('0' + (int)(x % 10));
            x /= 10;
        }

        if (neg)
            s.push_back('-');
        reverse(s.begin(), s.end());
        return s;
    };

    cout << toString(f.num) << "/" << toString(f.den) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;
        Fraction ans = solve(n, m);
        printFraction(ans);
    }

    return 0;
}