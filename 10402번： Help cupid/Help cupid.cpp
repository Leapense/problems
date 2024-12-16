#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    for (auto &x : T) cin >> x;

    vector<int> C(25, 0);

    for (auto x : T) {
        int shifted = x + 12;
        C[shifted]++;
    }

    struct Pair {
        int t, s, cost;
    };

    vector<Pair> pairs;

    for (int t = 1; t <= 24; t++) {
        for (int s = t; s <= 24; s++) {
            int diff = abs(t - s);
            int cost = min(diff, 24 - diff);
            pairs.push_back(Pair{t, s, cost});
        }
    }

    sort(pairs.begin(), pairs.end(), [&](const Pair &a, const Pair &b) -> bool {
        if (a.cost != b.cost) return a.cost < b.cost;
        return false;
    });

    long long total_cost = 0;
    for (auto &p : pairs) {
        if (p.t == p.s) {
            long long num = C[p.t] / 2;
            if (num > 0) {
                total_cost += num * 1LL * p.cost;
                C[p.t] -= num * 2;
            }
        }
        else
        {
            long long num = min((long long)C[p.t], (long long)C[p.s]);
            if (num > 0) {
                total_cost += num * 1LL * p.cost;
                C[p.t] -= num;
                C[p.s] -= num;
            }
        }
    }
    cout << total_cost << "\n";

    return 0;
}