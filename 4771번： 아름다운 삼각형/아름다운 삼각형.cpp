#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

bool isEqual(double a, double b, double eps = EPS) {
    return abs(a - b) < eps;
}

double distanceBetween(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, x2, y2, x3, y3;

    while (cin >> x1) {
        if (isEqual(x1, -1.0)) {
            break;
        }

        if(!(cin >> y1 >> x2 >> y2 >> x3 >> y3)) {
            break;
        }

        double a = distanceBetween(x2, y2, x3, y3);
        double b = distanceBetween(x1, y1, x3, y3);
        double c = distanceBetween(x1, y1, x2, y2);

        double area = fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;

        if (area <= EPS) {
            cout << "Not a Triangle\n";
            continue;
        }

        string sideClass;

        if (isEqual(a, b) && isEqual(b, c)) {
            sideClass = "Equilateral";
        } else if (isEqual(a, b) || isEqual(b, c) || isEqual(a, c)) {
            sideClass = "Isosceles";
        } else {
            sideClass = "Scalene";
        }

        vector<double> sides = {a, b, c};
        sort(sides.begin(), sides.end());

        double s1 = sides[0];
        double s2 = sides[1];
        double s3 = sides[2];

        double s1_sq = s1 * s1;
        double s2_sq = s2 * s2;
        double s3_sq = s3 * s3;

        string angleClass;
        double sum_squares = s1_sq + s2_sq;
        if (isEqual(sum_squares, s3_sq)) {
            angleClass = "Right";
        } else if (sum_squares > s3_sq + EPS) {
            angleClass = "Acute";
        } else {
            angleClass = "Obtuse";
        }

        cout << sideClass << " " << angleClass << "\n";
    }

    return 0;
}