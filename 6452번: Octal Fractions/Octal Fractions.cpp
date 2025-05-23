#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeLeadingZeros(string s)
{
    int pos = 0;
    while (pos < s.size() && s[pos] == '0')
        pos++;
    if (pos == s.size())
        return "0";
    return s.substr(pos);
}

string add(string a, int b)
{
    int carry = b;
    int i = a.size() - 1;
    string res = a;
    while (i >= 0 || carry)
    {
        if (i >= 0)
        {
            int sum = (res[i] - '0') + carry;
            res[i] = char('0' + sum % 10);
            carry = sum / 10;
            i--;
        }
        else
        {
            res.insert(res.begin(), char('0' + carry % 10));
            carry /= 10;
        }
    }

    return removeLeadingZeros(res);
}

string multiply(string a, int b)
{
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int prod = (a[i] - '0') * b + carry;
        a[i] = char('0' + prod % 10);
        carry = prod / 10;
    }

    while (carry)
    {
        a.insert(a.begin(), char('0' + carry % 10));
        carry /= 10;
    }

    return removeLeadingZeros(a);
}

string multiplyStr(string a, string b)
{
    int n = a.size(), m = b.size();
    string result(n + m, '0');
    for (int i = n - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            int sum = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            result[i + j + 1] = char('0' + sum % 10);
            carry = sum / 10;
        }

        result[i] = char((result[i] - '0' + carry) + '0');
    }

    return removeLeadingZeros(result);
}

int compare(string a, string b)
{
    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);
    if (a.size() < b.size())
        return -1;
    if (a.size() > b.size())
        return 1;
    if (a == b)
        return 0;

    return a < b ? -1 : 1;
}

string subtract(string a, string b)
{
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string res = a;
    while (j >= 0 || carry)
    {
        int ai = i >= 0 ? res[i] - '0' : 0;
        int bj = j >= 0 ? b[j] - '0' : 0;
        int sub = ai - bj - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        res[i] = char('0' + sub);
        i--;
        j--;
    }

    return removeLeadingZeros(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (getline(cin, s))
    {
        if (s == "")
            continue;
        string oct = s;
        int k = s.size() - 2;
        string numerator = "0";
        for (int i = 2; i < s.size(); i++)
        {
            numerator = multiply(numerator, 8);
            numerator = add(numerator, s[i] - '0');
        }

        string denominator = "1";

        for (int i = 0; i < k; i++)
        {
            denominator = multiply(denominator, 8);
        }

        string result = "";
        string rem = numerator;
        if (rem == "0")
            result = "0";
        while (rem != "0")
        {
            rem = multiply(rem, 10);
            int digit = 0;
            for (int d = 0; d <= 9; d++)
            {
                string prod = multiply(denominator, d);
                if (compare(prod, rem) > 0)
                {
                    digit = d - 1;
                    break;
                }
                if (d == 9)
                    digit = 9;
            }

            string prod = multiply(denominator, digit);
            rem = subtract(rem, prod);
            result.push_back(char('0' + digit));
        }

        cout << oct << " [8] = 0." << result << " [10]\n";
    }

    return 0;
}