#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    int index;
};

bool comparePoints(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int total = 3 * n;
        vector<Point> points(total);
        for (int i = 0; i < total; ++i) {
            cin >> points[i].x >> points[i].y;
            points[i].index = i + 1;
        }

        sort(points.begin(), points.end(), comparePoints);

        for (int i = 0; i < n; ++i) {
            int start = 3 * i;
            cout << points[start].index << " " << points[start + 1].index << " " << points[start + 2].index << "\n";
        }
    }

    return 0;
}