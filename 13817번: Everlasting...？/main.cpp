#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int compute_key_number(int n)
{
    set<int> factors;
    int temp = n;

    while (temp % 2 == 0)
    {
        factors.insert(2);
        temp /= 2;
    }

    for (int i = 3; i <= sqrt(temp); i += 2)
    {
        while (temp % i == 0)
        {
            factors.insert(i);
            temp /= i;
        }
    }

    if (temp > 1)
    {
        factors.insert(temp);
    }

    int max_factor = 0, sum = 0;
    for (int f : factors)
    {
        if (f > max_factor)
        {
            max_factor = f;
        }

        sum += f;
    }

    return max_factor - (sum - max_factor);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0))
    {
        int keyA = compute_key_number(a);
        int keyB = compute_key_number(b);

        cout << (keyA > keyB ? "a" : "b") << "\n";
    }

    return 0;
}