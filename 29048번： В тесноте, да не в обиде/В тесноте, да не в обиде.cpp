#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    long long n, m, p;
    cin >> n >> m >> p;

    if (n * m < 3)
    {
        cout << "NO";
        return 0;
    }

    bool possible = false;

    if (n == 1 || m == 1)
    {
        if (n == 1 && m >= 3)
        {
            if (p == 6 + 2 * m)
                possible = true;
        }
        if (m == 1 && n >= 3)
        {
            if (p == 6 + 2 * n)
                possible = true;
        }

        cout << (possible ? "YES" : "NO");
        return 0;
    }

    if (m >= 3 && p == 6 * n + 2 * m)
    {
        possible = true;
    }

    if (n >= 3 && p == 6 * m + 2 * n)
    {
        possible = true;
    }

    long long L1 = 2 * (2 * n + m + 1);
    long long L2 = 2 * (n + 2 * m + 1);
    long long L = min(L1, L2);
    long long R = 2 * (2 * n + 2 * m - 1);

    if (p % 2 == 0 && p >= L && p <= R)
    {
        possible = true;
    }

    cout << (possible ? "YES" : "NO");
    return 0;
}