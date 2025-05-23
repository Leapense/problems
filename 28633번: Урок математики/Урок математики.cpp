#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double G1, G2, G3;
    cin >> G1 >> G2 >> G3;

    double a = (G1 * G2) / G3;
    double b = (G1 * G3) / G2;
    double c = (G2 * G3) / G1;

    cout << fixed << setprecision(15) << a << "\n" << b << "\n" << c;

    return 0;
}