#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, q, r, s;
    while (cin >> p >> q >> r >> s)
    {
        int m = q < s ? q : s;
        long double result = 1.0L;
        for (int i = 1; i <= m; i++)
        {
            result *= (long double)(p - q + i) / (long double)(r - s + i);
        }
        if (q > s)
        {
            for (int i = m + 1; i <= q; i++)
            {
                result *= (long double)(p - q + i) / i;
            }
        }
        else if (s > q)
        {
            for (int i = m + 1; i <= s; i++)
            {
                result *= i / (long double)(r - s + i);
            }
        }
        cout << fixed << setprecision(5) << result << "\n";
    }
    return 0;
}
