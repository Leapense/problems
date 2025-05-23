#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y, idx;
};

bool compare(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i + 1; // Ensure indices start from 1
    }
    sort(points.begin(), points.end(), compare);
    for (int i = 0; i < N; i++) cout << points[i].idx << "\n";
    cout << points[0].idx;
    return 0;
}