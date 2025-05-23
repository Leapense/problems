#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> angles;
    for (int i = 0; i < n; i++) {
        string name;
        double d;
        cin >> name >> d;
        angles.push_back(d);
    }

    sort(angles.begin(), angles.end());
    angles.erase(unique(angles.begin(), angles.end(), [&](double a, double b) -> bool {
        return abs(a - b) < 1e-9;
    }), angles.end());

    int m = angles.size();
    if (m == 1) {
        cout << "0";
        return 0;
    }

    double max_gap = 0.0;
    for(int i = 1; i < m; i++) max_gap = max(max_gap, angles[i] - angles[i - 1]);
    max_gap = max(max_gap, 360 - angles[m - 1] + angles[0]);
    double minimal_angle = 360.0 - max_gap;
    double time = minimal_angle * 12.0;
    long long result = ceil(time - 1e-9);
    cout << result;

    return 0;
}