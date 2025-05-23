#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, K;
    cin >> N >> K;

    vector<long long> stations(N);
    for (auto &x : stations) {
        cin >> x;
    }

    vector<long long> relevant_stations;

    for (auto x : stations) {
        if (x <= K) {
            relevant_stations.push_back(x);
        }
    }

    sort(relevant_stations.begin(), relevant_stations.end());

    relevant_stations.erase(unique(relevant_stations.begin(), relevant_stations.end()), relevant_stations.end());

    vector<long long> points;
    points.push_back(0);

    for (auto x: relevant_stations) {
        points.push_back(x);
    }

    points.push_back(K);

    long long max_gap = 0;

    for (int i = 1; i < points.size(); ++i) {
        long long gap = points[i] - points[i - 1];

        if (gap > max_gap) {
            max_gap = gap;
        }
    }

    cout << max_gap;

    return 0;
}