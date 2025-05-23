#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int sumOfSquares(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    set<int> seen;
    while (n != 1 && seen.find(n) == seen.end())
    {
        seen.insert(n);
        n = sumOfSquares(n);
    }

    return n == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;

    while (P--)
    {
        int idx, m;
        cin >> idx >> m;
        bool result = isPrime(m) && isHappy(m);
        cout << idx << " " << m << " " << (result ? "YES" : "NO") << "\n";
    }

    return 0;
}