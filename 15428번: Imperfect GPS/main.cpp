#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
    double x, y, t;
};
double distance(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<Point> pts(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y >> pts[i].t;
    }

    double actual = 0;
    for (int i = 1; i < n; i++)
    {
        actual += distance(pts[i - 1], pts[i]);
    }

    vector<Point> gps;
    gps.push_back(pts[0]);
    double currentTime = t;

    int curIndex = 1;

    while (currentTime < pts.back().t)
    {
        while (curIndex < n && pts[curIndex].t < currentTime)
            curIndex++;
        Point prev = pts[curIndex - 1], next = pts[curIndex];
        double ratio = (currentTime - prev.t) / (next.t - prev.t);
        Point p{prev.x + ratio * (next.x - prev.x), prev.y + ratio * (next.y - prev.y), currentTime};
        gps.push_back(p);
        currentTime += t;
    }

    gps.push_back(pts.back());

    double gpsDist = 0;
    for (int i = 1; i < gps.size(); i++)
    {
        gpsDist += distance(gps[i - 1], gps[i]);
    }

    double lossPercentage = ((actual - gpsDist) / actual) * 100;
    cout << fixed << setprecision(12) << lossPercentage << "\n";

    return 0;
}