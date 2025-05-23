#include <iostream>
#include <iomanip>
using namespace std;

long double comb(int n, int r)
{
    long double res = 1.0;
    if (r > n - r)
        r = n - r;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - r + i);
        res /= i;
    }

    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        int sum = a + b;

        long double total = comb(26, 13);
        long double ways = comb(sum, a) * comb(26 - sum, 13 - a);
        if (a != b)
            ways *= 2;
        long double probability = ways / total;
        cout << a << "-" << b << " split: ";
        cout << fixed << setprecision(8) << probability << "\n";
    }

    return 0;
}