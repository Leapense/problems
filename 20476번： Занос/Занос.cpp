#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double v, x, y, a, b;
    cin >> v >> x >> y >> a >> b;

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

    double total_time = t1 + t2;

    cout << fixed << setprecision(8) << total_time << "\n";

    return 0;
}