#include <bits/stdc++.h>
using namespace std;

static string solve_point(long double H, long double V,
                          long double hFrac, long double vFrac,
                          long double x, long double y) {
    long double X = x / H;
    long double Y = y / V;

    int color = 0;
    const long double h = hFrac, v = vFrac;
    const int kMax = 1'000'000;

    for (int iter = 0; iter < kMax; ++iter)
    {
        bool left = X < h;
        bool below = Y < v;

        if (left != below) break;
        color ^= 1;

        if (left)
        {
            X /= h;
            Y /= v;
        }
        else
        {
            X = (X - h) / (1 - h);
            Y = (Y - v) / (1 - v);
        }
    }

    return color ? "white" : "black";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double H, V, h, v;
    int tc = 1;

    while (cin >> H >> V >> h >> v)
    {
        if (H == 0 && V == 0 && h == 0 && v == 0) break;
        int n;
        cin >> n;

        cout << "Case " << tc++ << ":\n";
        for (int i = 0; i < n; ++i)
        {
            long double x, y;
            cin >> x >> y;
            cout << solve_point(H, V, h, v, x, y) << "\n";
        }
    }

    return 0;
}