#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string stripLeadingZeros(const string &s)
{
    size_t pos = s.find_first_not_of('0');
    if (pos == string::npos)
        return "0";
    return s.substr(pos);
}

int compareBig(const string &a, const string &b)
{
    string A = stripLeadingZeros(a), B = stripLeadingZeros(b);
    if (A.size() < B.size())
        return -1;
    if (A.size() > B.size())
        return 1;
    if (A < B)
        return -1;
    if (A > B)
        return 1;
    return 0;
}

string subtractBig(const string &a, const string &b)
{
    string A = stripLeadingZeros(a), B = stripLeadingZeros(b);
    int cmp = compareBig(A, B);
    if (cmp == 0)
        return "0";
    // a >= b assumed
    int i = A.size() - 1, j = B.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0)
    {
        int d1 = (i >= 0) ? A[i] - '0' : 0;
        int d2 = (j >= 0) ? B[j] - '0' : 0;
        int sub = d1 - d2 - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        res.push_back('0' + sub);
        i--;
        j--;
    }
    reverse(res.begin(), res.end());
    return stripLeadingZeros(res);
}

string multiplyBig(const string &a, int x)
{
    if (x == 0 || a == "0")
        return "0";
    int carry = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int prod = (a[i] - '0') * x + carry;
        carry = prod / 10;
        res.push_back('0' + prod % 10);
    }
    while (carry)
    {
        res.push_back('0' + carry % 10);
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return stripLeadingZeros(res);
}

string addBig(const string &a, const string &b)
{
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry)
    {
        int d1 = (i >= 0) ? a[i] - '0' : 0;
        int d2 = (j >= 0) ? b[j] - '0' : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        res.push_back('0' + sum % 10);
        i--;
        j--;
    }
    reverse(res.begin(), res.end());
    return stripLeadingZeros(res);
}

string modBig(const string &a, const string &b)
{
    string dividend = stripLeadingZeros(a);
    string divisor = stripLeadingZeros(b);
    if (compareBig(dividend, divisor) < 0)
        return dividend;
    string rem = "0";
    for (char ch : dividend)
    {
        rem.push_back(ch);
        rem = stripLeadingZeros(rem);
        int count = 0;
        while (compareBig(rem, divisor) >= 0)
        {
            rem = subtractBig(rem, divisor);
            count++;
        }
    }
    return stripLeadingZeros(rem);
}

string gcdBig(string a, string b)
{
    a = stripLeadingZeros(a);
    b = stripLeadingZeros(b);
    if (b == "0")
        return a;
    string r = modBig(a, b);
    return gcdBig(b, r);
}

string modOfBig(const string &a, const string &b)
{ // a mod b
    return modBig(a, b);
}

string addMod(const string &a, const string &b, const string &mod)
{
    string sum = addBig(a, b);
    string res = modBig(sum, mod);
    return res;
}

string subtractMod(const string &a, const string &b, const string &mod)
{
    // compute (a - b) mod mod, assume a>=b? we'll adjust:
    string cmp = (compareBig(a, b) < 0 ? addBig(a, mod) : a);
    string res = subtractBig(cmp, b);
    res = modBig(res, mod);
    return res;
}

string computeY(const string &T_gcd, const string &m)
{
    string rem = modBig(m, T_gcd);
    if (rem == "0")
        return "0";
    // y = T_gcd - rem
    return subtractBig(T_gcd, rem);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
        vector<string> times(N);
        for (int i = 0; i < N; i++)
        {
            cin >> times[i];
            times[i] = stripLeadingZeros(times[i]);
        }
        // m = max(times)
        string m = times[0];
        for (int i = 1; i < N; i++)
        {
            if (compareBig(times[i], m) > 0)
                m = times[i];
        }
        string T_gcd = "0";
        for (int i = 0; i < N; i++)
        {
            string diff = subtractBig(m, times[i]);
            if (i == 0)
                T_gcd = diff;
            else
                T_gcd = gcdBig(T_gcd, diff);
        }
        string y = computeY(T_gcd, m);
        cout << "Case #" << tc << ": " << y << "\n";
    }
    return 0;
}