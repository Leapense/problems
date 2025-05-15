#include <bits/stdc++.h>
using namespace std;

const long double g = 9.8L;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while ((cin >> n)) {
        vector<long double> h(n+1), d(n+1);
        cin >> h[1] >> d[1];
        for (int i = 2; i < n; i++) {
            cin >> h[i] >> d[i];
        }
        cin >> h[n] >> d[n];

        long double S = accumulate(d.begin() + 1, d.begin() + n + 1, 0.L);

        long double tmax = 0;
        long double x = 0;

        for (int i = 1; i <= n; i++)
        {
            long double x0 = x;
            long double x1 = x + d[i];
            if (i > 1 && i < n)
            {
                auto check = [&](long double xi) {
                    long double denom = xi * (1 - xi / S);
                    if (denom > 0) {
                        tmax = max(tmax, h[i] / denom);
                    }
                };

                check(x0);
                check(x1);
            }

            x = x1;
        }

        long double theta = atan(tmax);
        long double deg = theta * 180.0L / acosl(-1.0L);
        long double vt2 = S * g / (sinl(2 * theta));
        long double v = sqrtl(vt2);
        cout << fixed << setprecision(2) << deg << " " << v << "\n";
    }

    return 0;
}