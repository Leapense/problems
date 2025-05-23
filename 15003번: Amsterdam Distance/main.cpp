#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int M, N;
    double R;
    cin >> M >> N >> R;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    double ans = 1e9;
    int kmax = min(ay, by);

    for (int k = 0; k <= kmax; k++)
    {
        double d = (ay - k) * (R / N) + (by - k) * (R / N);
        if (k > 0)
        {
            d += abs(ax - bx) * (M_PI * (k * R / N) / M);
        }
        ans = min(ans, d);
    }

    cout << fixed;
    cout.precision(12);
    cout << ans;
    return 0;
}