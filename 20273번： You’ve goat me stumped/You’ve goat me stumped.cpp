#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    const double PI = 3.14159265358979323846;
    while (c--) {
        int l, r;
        cin >> l >> r;
        double area = 0.0;

        if (l > r) {
            area = 0.0;
        } else {
            if (l == 0) {
                double a = r / 2.0;
                area = PI * a * a;
            } else {
                double a = r / 2.0;
                double c_focal = l / 2.0;
                if (a < c_focal) {
                    area = 0.0;
                } else {
                    double b = sqrt(a * a - c_focal * c_focal);
                    area = PI * a * b;
                }
            }
        }

        double rounded = round(area / 100.0);
        long long rounded_area = (long long)(rounded) * 100;
        cout << rounded_area << "\n";
    }

    return 0;
}