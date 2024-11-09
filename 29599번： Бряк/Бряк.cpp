#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);
    vector<double> s(n + 1, 0.0);

    for (int i = 1; i <= n; i++) {
        long long vi;
        int ci;

        cin >> vi >> ci;

        v[i] = vi;
        s[i] = vi * (double)ci / 100.0;
    }

    int m;
    cin >> m;


    for (int i = 0; i < m; i++) {
        int a, b;
        long long k;

        cin >> a >> b >> k;

        double c_a;
        if (v[a] > 0) {
            c_a = s[a] / (double)v[a];
        } else {
            c_a = 0.0;
        }

        double s_poured = (double)k * c_a;

        v[a] -= k;
        s[a] -= s_poured;

        v[b] += k;
        s[b] += s_poured;
    }

    cout << n << "\n";

    cout << fixed << setprecision(4);

    for (int i = 1; i <= n; i++) {
        double ci;
        if (v[i] > 0) {
            ci = s[i] / (double)v[i] * 100.0;
        } else {
            ci = 0.0;
        }

        if (abs(ci) < 1e-9) {
            ci = 0.0;
        }
        cout << v[i] << " " << ci << "\n";
    }

    return 0;
}