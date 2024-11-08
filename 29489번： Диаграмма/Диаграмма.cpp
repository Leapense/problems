#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int &x : p) {
        cin >> x;
    }

    const double pi = acos(-1.0);

    for (int i = 0; i < n; ++i) {
        double theta = 2.0 * pi * i / n;

        double x = p[i] * cos(theta);
        double y = p[i] * sin(theta);

        if (abs(x) < 1e-9) x = 0.0;
        if (abs(y) < 1e-9) y = 0.0;

        cout << fixed << setprecision(6) << x << " " << y << "\n";
    }

    return 0;
}