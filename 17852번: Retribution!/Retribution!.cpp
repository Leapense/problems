#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
    int x, y;
};

struct Pair
{
    int judge;
    int loc;
    double dist;
};

double euclideanDistance(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double greedyMatching(const vector<Point> &judges, const vector<Point> &locations)
{
    int n = judges.size();
    int m = locations.size();
    vector<Pair> pairs;
    pairs.reserve(n * m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            double d = euclideanDistance(judges[i], locations[j]);
            pairs.push_back({i, j, d});
        }
    }

    sort(pairs.begin(), pairs.end(), [](const Pair &a, const Pair &b)
         {
        if (a.dist != b.dist) return a.dist < b.dist;
        if (a.judge != b.judge) return a.judge < b.judge;
        return a.loc < b.loc; });

    double totalDistance = 0.0;
    vector<bool> judgeAssigned(n, false);
    vector<bool> locAssigned(m, false);
    int assignedCount = 0;

    for (const auto &pr : pairs)
    {
        if (assignedCount == n)
            break;
        if (!judgeAssigned[pr.judge] && !locAssigned[pr.loc])
        {
            judgeAssigned[pr.judge] = true;
            locAssigned[pr.loc] = true;
            totalDistance += pr.dist;
            assignedCount++;
        }
    }

    return totalDistance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;

    vector<Point> judges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> judges[i].x >> judges[i].y;
    }

    vector<Point> tarRepos(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> tarRepos[i].x >> tarRepos[i].y;
    }

    vector<Point> featherStores(p);
    for (int i = 0; i < p; ++i)
    {
        cin >> featherStores[i].x >> featherStores[i].y;
    }

    double totalTarDistance = greedyMatching(judges, tarRepos);
    double totalFeatherDistance = greedyMatching(judges, featherStores);
    double totalDistance = totalTarDistance + totalFeatherDistance;
    cout << fixed << setprecision(6) << totalDistance << "\n";

    return 0;
}