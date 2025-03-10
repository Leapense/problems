#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
        double sumX = 0, sumY = 0, sumZ = 0;
        double sumVX = 0, sumVY = 0, sumVZ = 0;

        for (int i = 0; i < N; i++)
        {
            double x, y, z, vx, vy, vz;
            cin >> x >> y >> z >> vx >> vy >> vz;
            sumX += x;
            sumY += y;
            sumZ += z;
            sumVX += vx;
            sumVY += vy;
            sumVZ += vz;
        }

        double x_avg = sumX / N;
        double y_avg = sumY / N;
        double z_avg = sumZ / N;
        double vx_avg = sumVX / N;
        double vy_avg = sumVY / N;
        double vz_avg = sumVZ / N;

        double tmin;
        double v2 = vx_avg * vx_avg + vy_avg * vy_avg + vz_avg * vz_avg;
        if (v2 == 0)
        {
            tmin = 0.0;
        }
        else
        {
            tmin = -(x_avg * vx_avg + y_avg * vy_avg + z_avg * vz_avg) / v2;
            if (tmin < 0)
                tmin = 0.0;
        }

        double dx = x_avg + vx_avg * tmin;
        double dy = y_avg + vy_avg * tmin;
        double dz = z_avg + vz_avg * tmin;

        double dmin = sqrt(dx * dx + dy * dy + dz * dz);

        cout << "Case #" << tc << ": " << fixed << setprecision(8) << dmin << " " << tmin;
        if (tc < T)
            cout << "\n";
    }

    return 0;
}