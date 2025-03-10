#include <iostream>
#include <string>

using namespace std;

long long ten_pow(int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= 10;
    }
    return res;
}

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line == "0")
        {
            break;
        }
        string s = line.substr(2, line.size() - 5);
        long long full = stoll(s);
        int k = s.length();
        long long A = full / 10;
        int b = full % 10;
        long long numerator = 9 * A + b;
        long long denominator = 9 * ten_pow(k - 1);
        long long gcd_val = gcd(numerator, denominator);
        long long simp_num = numerator / gcd_val;
        long long simp_den = denominator / gcd_val;
        cout << simp_num << "/" << simp_den << endl;
    }
    return 0;
}