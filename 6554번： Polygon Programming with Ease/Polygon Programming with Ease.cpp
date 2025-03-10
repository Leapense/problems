#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<double> m(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> m[i];
        }
        vector<double> f(2 * n);
        double x = m[2 * (n - 1)], y = m[2 * (n - 1) + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int exp = n - 2 - i;
            int sign = (exp % 2 == 0) ? 1 : -1;
            x -= sign * m[2 * i];
            y -= sign * m[2 * i + 1];
        }
        f[0] = x;
        f[1] = y;
        for (int i = 1; i < n; i++)
        {
            f[2 * i] = 2 * m[2 * (i - 1)] - f[2 * (i - 1)];
            f[2 * i + 1] = 2 * m[2 * (i - 1) + 1] - f[2 * (i - 1) + 1];
        }
        cout << n;
        cout << fixed << setprecision(6);
        for (int i = 0; i < n; i++)
        {
            cout << " " << f[2 * i] << " " << f[2 * i + 1];
        }
        cout << "\n";
    }
    return 0;
}