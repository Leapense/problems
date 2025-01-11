#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<double, double>> points(N);
    for (auto &p : points) cin >> p.first >> p.second;

    while (Q--) {
        double qx, qy;
        cin >> qx >> qy;

        vector<double> distances(N);
        for (int i = 0; i < N; i++) {
            distances[i] = sqrt((points[i].first - qx) * (points[i].first - qx) + (points[i].second - qy) * (points[i].second - qy));
        }

        sort(distances.begin(), distances.end());

        int total = 0;
        int start = 0;

        while (start < N) {
            int end = start + 1;
            while (end < N && abs(distances[end] - distances[start]) < 0.0001) end++;

            int k = end - start;

            if (k >= 2) total += k * (k - 1) / 2;

            start = end;
        }

        cout << total << "\n";
    }


    return 0;
}