#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> intervals;

    for (int i = 1; i <= n; ++i) {
        if (i < a[i]) {
            intervals.push_back({i, a[i]});
        } else {
            intervals.push_back({a[i], i});
        }
    }

    sort(intervals.begin(), intervals.end());

    int total_distance = 0;
    int current_end = 0;

    for (auto interval : intervals) {
        if (interval.first > current_end) {
            total_distance += interval.second - interval.first;
            current_end = interval.second;
        } else if (interval.second > current_end) {
            total_distance += interval.second - current_end;
            current_end = interval.second;
        }
    }

    cout << total_distance << '\n';
    return 0;
}