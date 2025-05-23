#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, c, m, R0;

    cin >> a >> c >> m >> R0;

    vector<bool> seen(m, false);
    vector<int> vals;

    long long R = R0;
    while (!seen[R]) {
        seen[R] = true;
        vals.push_back(R);
        R = (a * R + c) % m;
    }

    sort(vals.begin(), vals.end());
    long long max_gap = 0;
    for (int i = 1; i < vals.size(); i++) {
        long long gap = vals[i] - vals[i - 1];
        if (gap > max_gap) max_gap = gap;
    }

    cout << max_gap << "\n";

    return 0;
}