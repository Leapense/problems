#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
    long long x, y;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<Point> ground(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ground[i].x >> ground[i].y;
        }
        int m;
        cin >> m;
        vector<Point> water(m);
        for (int i = 0; i < m; i++)
        {
            cin >> water[i].x >> water[i].y;
        }
        int i = 0, j = 0;
        double ans = 1e18;
        while (i < n - 1 && j < m - 1)
        {
            long long L = max(ground[i].x, water[j].x);
            long long R = min(ground[i + 1].x, water[j + 1].x);
            double dx_g = (double)(ground[i + 1].x - ground[i].x);
            double dy_g = (double)(ground[i + 1].y - ground[i].y);
            double dx_w = (double)(water[j + 1].x - water[j].x);
            double dy_w = (double)(water[j + 1].y - water[j].y);
            auto get_ground = [&](long long X) -> double
            {
                return ground[i].y + dy_g * (X - ground[i].x) / dx_g;
            };
            auto get_water = [&](long long X) -> double
            {
                return water[j].y + dy_w * (X - water[j].x) / dx_w;
            };
            double diffL = get_ground(L) - get_water(L);
            double diffR = get_ground(R) - get_water(R);
            ans = min(ans, min(diffL, diffR));
            if (ground[i + 1].x == R && water[j + 1].x == R)
            {
                i++;
                j++;
            }
            else if (ground[i + 1].x == R)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        cout << fixed << setprecision(2) << ans << "\n";
    }
    return 0;
}
