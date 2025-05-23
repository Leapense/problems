#include <iostream>
#include <iomanip>
#include <cmath>
#include "main.h"
using namespace std;

double compute_min_time(double v, double x, double y, double a, double b)
{
    double t1;
    double d = (v * v) / (2 * b);

    if (d <= x)
    {
        t1 = (x - d) / v + v / b;
    }
    else
    {
        double u = sqrt(2 * b * x);
        t1 = u / b;
    }

    double t2;
    double d2 = (v * v) / (2 * a);

    if (d2 <= y)
    {
        t2 = v / a + (y - d2) / v;
    }
    else
    {
        t2 = sqrt(2 * y / a);
    }

    return t1 + t2;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double v, x, y, a, b;
    cin >> v >> x >> y >> a >> b;

    double result = compute_min_time(v, x, y, a, b);
    cout << fixed << setprecision(8) << result << "\n";
    return 0;
}
#endif