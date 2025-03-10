#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string multiply(const string &num, int multiplier)
{
    int carry = 0;
    string result(num.size(), '0');

    for (int i = num.size() - 1; i >= 0; --i)
    {
        int prod = (num[i] - '0') * multiplier + carry;
        carry = prod / 10;
        result[i] = '0' + prod % 10;
    }

    while (carry)
    {
        char digit = '0' + (carry % 10);
        result.insert(result.begin(), digit);
        carry /= 10;
    }

    return result;
}

int main()
{
    int n;
    while (cin >> n && n != -1)
    {
        string fact = "1";
        for (int i = 2; i <= n - 1; i++)
        {
            fact = multiply(fact, i);
        }

        fact = multiply(fact, 2);
        cout << "N=" << n << ":\n"
             << fact << "\n";
    }

    return 0;
}