#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M, S;
    cin >> N >> M >> S;

    vector<pair<long long, long long>> exams(N);
    for (auto &p : exams) cin >> p.first >> p.second;

    sort(exams.begin(), exams.end());

    long long prev_end = 0;
    for (auto &[x, y] : exams) {
        if (x - prev_end >= M) {
            cout << prev_end;
            return 0;
        }
        prev_end = max(prev_end, x + y);
    }

    if (S - prev_end >= M) {
        cout << prev_end;
    }
    else {
        cout << -1;
    }

    return 0;
}