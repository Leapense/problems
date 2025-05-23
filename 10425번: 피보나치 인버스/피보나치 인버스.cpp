#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct BigInt
{
    vector<long long> digits;
    static const long long BASE = 1000000000;
    BigInt() {}
    BigInt(const string &s)
    {
        for (int i = s.size(); i > 0; i -= 9)
        {
            int start = max(0, i - 9);
            digits.push_back(stoll(s.substr(start, i - start)));
        }
        trim();
    }
    BigInt(long long v)
    {
        while (v)
        {
            digits.push_back(v % BASE);
            v /= BASE;
        }
    }
    void trim()
    {
        while (!digits.empty() && digits.back() == 0)
            digits.pop_back();
    }
    string toString() const
    {
        if (digits.empty())
            return "0";
        string s = to_string(digits.back());
        for (int i = digits.size() - 2; i >= 0; i--)
        {
            string part = to_string(digits[i]);
            s += string(9 - part.size(), '0') + part;
        }
        return s;
    }
};

BigInt add(const BigInt &a, const BigInt &b)
{
    BigInt res;
    int n = max(a.digits.size(), b.digits.size());
    long long carry = 0;
    for (int i = 0; i < n || carry; i++)
    {
        long long av = (i < a.digits.size() ? a.digits[i] : 0);
        long long bv = (i < b.digits.size() ? b.digits[i] : 0);
        long long sum = av + bv + carry;
        res.digits.push_back(sum % BigInt::BASE);
        carry = sum / BigInt::BASE;
    }
    res.trim();
    return res;
}

BigInt multiply(const BigInt &a, const BigInt &b)
{
    BigInt res;
    res.digits.resize(a.digits.size() + b.digits.size());
    for (size_t i = 0; i < a.digits.size(); i++)
    {
        long long carry = 0;
        for (size_t j = 0; j < b.digits.size() || carry; j++)
        {
            long long bv = (j < b.digits.size() ? b.digits[j] : 0);
            long long sum = res.digits[i + j] + a.digits[i] * bv + carry;
            res.digits[i + j] = sum % BigInt::BASE;
            carry = sum / BigInt::BASE;
        }
    }
    res.trim();
    return res;
}

int compare(const BigInt &a, const BigInt &b)
{
    if (a.digits.size() != b.digits.size())
        return a.digits.size() < b.digits.size() ? -1 : 1;
    for (int i = a.digits.size() - 1; i >= 0; i--)
    {
        if (a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i] ? -1 : 1;
    }
    return 0;
}

pair<BigInt, BigInt> fibPair(int n)
{
    if (n == 0)
        return {BigInt(0), BigInt(1)};
    auto p = fibPair(n >> 1);
    BigInt c = multiply(p.first, add(multiply(BigInt(2), p.second), BigInt(-(p.first.toString() == "0" ? 0 : 0))));
    // Instead of using subtraction with negative BigInt, we compute:
    BigInt temp = add(multiply(BigInt(2), p.second), BigInt());
    // We need to compute (2*p.second - p.first)
    // Let's implement subtraction:
    auto subtract = [&](const BigInt &A, const BigInt &B) -> BigInt
    {
        BigInt res;
        res.digits.resize(max(A.digits.size(), B.digits.size()));
        long long carry = 0;
        for (size_t i = 0; i < res.digits.size(); i++)
        {
            long long av = (i < A.digits.size() ? A.digits[i] : 0);
            long long bv = (i < B.digits.size() ? B.digits[i] : 0);
            long long cur = av - bv - carry;
            carry = 0;
            if (cur < 0)
            {
                cur += BigInt::BASE;
                carry = 1;
            }
            res.digits[i] = cur;
        }
        res.trim();
        return res;
    };
    BigInt two_p = multiply(BigInt(2), p.second);
    BigInt diff = subtract(two_p, p.first);
    BigInt c_val = multiply(p.first, diff);
    BigInt d_val = add(multiply(p.first, p.first), multiply(p.second, p.second));
    if (n & 1)
        return {d_val, add(c_val, d_val)};
    return {c_val, d_val};
}

// Re-implementing fibPair with proper subtraction and no dependency on negative construction
pair<BigInt, BigInt> fibPairRec(int n)
{
    if (n == 0)
        return {BigInt(0), BigInt(1)};
    auto p = fibPairRec(n >> 1);
    auto subtract = [&](const BigInt &A, const BigInt &B) -> BigInt
    {
        BigInt res;
        res.digits.resize(max(A.digits.size(), B.digits.size()));
        long long carry = 0;
        for (size_t i = 0; i < res.digits.size(); i++)
        {
            long long av = (i < A.digits.size() ? A.digits[i] : 0);
            long long bv = (i < B.digits.size() ? B.digits[i] : 0);
            long long cur = av - bv - carry;
            carry = 0;
            if (cur < 0)
            {
                cur += BigInt::BASE;
                carry = 1;
            }
            res.digits[i] = cur;
        }
        res.trim();
        return res;
    };
    BigInt two_p = multiply(BigInt(2), p.second);
    BigInt diff = subtract(two_p, p.first);
    BigInt c = multiply(p.first, diff);
    BigInt d = add(multiply(p.first, p.first), multiply(p.second, p.second));
    if (n & 1)
        return {d, add(c, d)};
    else
        return {c, d};
}

BigInt getFib(int n)
{
    return fibPairRec(n).first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        string s;
        cin >> s;
        if (s == "0")
        {
            cout << 0 << "\n";
            continue;
        }
        if (s == "1")
        {
            cout << 2 << "\n";
            continue;
        }
        int len = s.size();
        int k = min(len, 15);
        long double lead = stold(s.substr(0, k));
        long double approx_log = log10(lead) + (len - k);
        long double phi = (1 + sqrt((long double)5)) / 2;
        long double indexApprox = (approx_log + log10(sqrt((long double)5))) / log10(phi);
        int candidate = (int)floor(indexApprox + 0.5L);
        int ans = -1;
        for (int d = -2; d <= 2; d++)
        {
            int cur = candidate + d;
            if (cur < 0)
                continue;
            string fibStr = getFib(cur).toString();
            if (fibStr == s)
                ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}
