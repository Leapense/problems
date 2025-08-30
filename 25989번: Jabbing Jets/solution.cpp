#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double e;
    if (!(cin >> n >> e)) return 0;

    const double PI = acos(-1.0);
    const double EPS = 1e-12;
    unsigned long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int ri;
        cin >> ri;
        double r = static_cast<double>(ri);
        if (e > 2.0 * r + EPS) {
            ans += 1ull;
        } else if (abs(e - 2.0 * r) <= EPS) {
            ans += 2ull;
        } else {
            double x = e / (2.0 * r);
            if (x < 0.0) x = 0.0;
            if (x > 1.0) x = 1.0;
            double alpha = 2.0 * asin(x);
            double k = (2.0 * PI) / alpha;
            unsigned long long cnt = static_cast<unsigned long long>(floor(k + 1e-12));
            if (cnt < 1ull) cnt = 1ull;
            ans += cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}