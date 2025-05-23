#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int s, r;
        cin >> s >> r;

        double area;
        double a = s / 2.0;

        if (r <= a)
        {
            area = PI * r * r;
        }
        else if (r >= a * sqrt(2.0))
        {
            area = s * s;
        }
        else
        {
            double term1 = 2 * s * sqrt(r * r - a * a);
            double term2 = 4 * r * r * asin(a / r);
            double term3 = r * r * PI;
            area = term1 + term2 - term3;
        }

        cout << fixed << setprecision(2) << area << "\n";
    }

    return 0;
}