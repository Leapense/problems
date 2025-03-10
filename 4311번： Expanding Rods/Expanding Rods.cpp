#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double L, n, C;
    while (cin >> L >> n >> C)
    {
        if (L < 0 && n < 0 && C < 0)
            break;
        double Lp = (1 + n * C) * L;
        if (Lp == L)
        {
            cout << fixed << setprecision(3) << 0.0 << "\n";
            continue;
        }

        double low = 0.0, high = M_PI, mid;
        for (int i = 0; i < 100; i++)
        {
            mid = (low + high) / 2;
            double ratio = mid / sin(mid);
            if (ratio < Lp / L)
                low = mid;
            else
                high = mid;
        }

        double x = mid;
        double R = L / (2 * sin(x / 1.0));
        double d = R * (1 - cos(x / 1.0));
        cout << fixed << setprecision(3) << d << "\n";
    }

    return 0;
}