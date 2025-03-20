#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string addStrings(const string &a, const string &b)
{
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string res;

    while (i >= 0 || j >= 0 || carry)
    {
        int s = carry;
        if (i >= 0)
            s += a[i--] - '0';
        if (j >= 0)
            s += b[j--] - '0';
        carry = s / 10;
        res.push_back((char)('0' + s % 10));
    }

    reverse(res.begin(), res.end());
    return res;
}

string multiplyStrings(const string &a, const string &b)
{
    if (a == "0" || b == "0")
        return "0";
    vector<int> res(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = res[i + j + 1] + mul;
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string s;
    for (auto num : res)
        if (!(s.empty() && num == 0))
            s.push_back('0' + num);

    return s.empty() ? "0" : s;
}

string divideString(const string &num, int divisor)
{
    string res;
    int idx = 0, rem = 0;
    while (idx < num.size())
    {
        rem = rem * 10 + (num[idx] - '0');
        int q = rem / divisor;
        res.push_back('0' + q);
        rem %= divisor;
        idx++;
    }

    size_t pos = res.find_first_not_of('0');
    return pos == string::npos ? "0" : res.substr(pos);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        unsigned long long N;
        cin >> N;

        string sN = to_string(N);
        string sN1 = to_string(N + 1);
        string sN2 = to_string(N + 2);
        string prod = multiplyStrings(sN, sN1);
        prod = multiplyStrings(prod, sN2);
        string half = divideString(prod, 6);
        string ans = multiplyStrings(half, half);

        cout << ans << "\n";
    }

    return 0;
}