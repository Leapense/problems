#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr double EPS = 1e-6;

struct Point {
    double x, y;
};

bool isEqual(double a, double b) {
    return fabs(a - b) <= EPS;
}

double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double dotProduct(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    for (int t = 1; t <= testCases; t++) {
        int p;
        cin >> p;

        vector<Point> points(p);
        for (int i = 0; i < p; i++) {
            cin >> points[i].x >> points[i].y;
        }

        int count = 0;
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                Point mid = {(points[i].x + points[j].x) / 2.0, (points[i].y + points[j].y) / 2.0};

                int mIndex = -1;
                for (int k = 0; k < p; k++) {
                    if (isEqual(points[k].x, mid.x) && isEqual(points[k].y, mid.y)) {
                        mIndex = k;
                        break;
                    }
                }

                if (mIndex == -1) continue;

                double AB = distance(points[i], points[j]);

                for (int c = 0; c < p; c++) {
                    if (c == i || c == j || c == mIndex) continue;

                    double MC = distance(points[c], points[mIndex]);
                    if (!isEqual(MC, AB)) {
                        continue;
                    }

                    Point vecAM = {points[i].x - points[mIndex].x, points[i].y - points[mIndex].y};
                    Point vecCM = {points[c].x - points[mIndex].x, points[c].y - points[mIndex].y};

                    if (!isEqual(dotProduct(vecAM, vecCM), 0.0)) {
                        continue;
                    }

                    count++;
                }
            }
        }

        cout << "Set #" << t << ": " << count << "\n\n";
    }

    return 0;
}