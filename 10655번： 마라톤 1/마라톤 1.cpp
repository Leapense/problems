#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (auto &p : points)
        cin >> p.first >> p.second;
    long long total = 0;
    for (int i = 0; i < N - 1; i++)
        total += abs(points[i + 1].first - points[i].first) + abs(points[i + 1].second - points[i].second);
    long long min_dist = LLONG_MAX;
    for (int i = 1; i < N - 1; i++)
    {
        long long temp = total - (abs(points[i].first - points[i - 1].first) + abs(points[i].second - points[i - 1].second)) - (abs(points[i + 1].first - points[i].first) + abs(points[i + 1].second - points[i].second)) + (abs(points[i + 1].first - points[i - 1].first) + abs(points[i + 1].second - points[i - 1].second));
        if (temp < min_dist)
            min_dist = temp;
    }
    cout << min_dist;
}
