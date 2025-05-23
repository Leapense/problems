#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int xm, vx, vy, xa, va, tK;
    cin >> xm >> vx >> vy >> xa >> va >> tK;

    double X = xm + vx * tK;
    double Y = vy * tK - 16.0 * tK * tK;
    if (Y <= 0)
    {
        cout << "start running";
        return 0;
    }

    double d = sqrt((X - xa) * (X - xa) + Y * Y);
    double T = d / va;
    double tL = tK - T;

    if (tL < 0)
    {
        cout << "start running";
        return 0;
    }

    double angle = atan2(Y, X - xa) * 180.0 / M_PI;
    cout << fixed << setprecision(8) << tL << " " << angle;
    return 0;
}