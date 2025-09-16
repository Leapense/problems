#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long x;
    long long s;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<Node> v;
    v.reserve(N);
    for (int i = 0; i < N; ++i) {
        long long x, h;
        cin >> x >> h;
        long long s = (h - 1) / 2;
        v.push_back({x, s});
    }

    sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
        return a.x < b.x;
    });

    const long long INF = (long long)9e18;
    long long earliest = INF;

    for (int i = 0; i + 1 < N; ++i) {
        long long d = v[i+1].x - v[i].x;
        long long a = min(v[i].s, v[i+1].s);
        long long b = max(v[i].s, v[i+1].s);

        if (d > a + b) continue;
        else if (d <= 2 * a) {
            long long ti = (d + 1) / 2;
            earliest = min(earliest, ti);
        } else {
            long long ti = d - a;
            earliest = min(earliest, ti);
        }
    }

    if (earliest == INF) {
        cout << "forever\n";
    } else {
        cout << (earliest - 1) << "\n";
    }

    return 0;
}