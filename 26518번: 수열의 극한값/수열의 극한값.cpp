#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double b, c, a1, a2;
    cin >> b >> c >> a1 >> a2;

    long double disc = b * b + 4.0L * c;
    long double sqrt_disc = sqrt(disc);
    long double root = (b + sqrt_disc) / 2.0L;

    cout << fixed << setprecision(9) << root << "\n";
    return 0;
}