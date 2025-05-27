#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) {
        return 0;
    }

    if (N == 0) {
        cout << 0;
        return 0;
    }

    vector<pair<long long, int>> events;
    events.reserve(2LL * N);

    for (int i = 0; i < N; ++i) {
        long long a, b;
        cin >> a >> b;
        events.emplace_back(a, +1);
        events.emplace_back(b, -1);
    }

    sort(events.begin(), events.end(), [](auto &l, auto &r) {
        if (l.first != r.first) return l.first < r.first;
        return l.second > r.second;
    });

    long long currentDepth = 0;
    long long maxDepth = 0;
    for (auto &[pos, delta] : events) {
        currentDepth += delta;
        maxDepth = max(maxDepth, currentDepth);
    }

    cout << maxDepth;
    return 0;
}