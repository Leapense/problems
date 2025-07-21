#include <bits/stdc++.h>
using namespace std;

struct Car { long long time; int dir; int idx; };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<Car>> incoming(4);
    auto dirIndex = [](char c) { return c == 'U' ? 0 : c == 'L' ? 1 : c == 'D' ? 2 : 3; };
    for (int i = 0; i < n; ++i) {
        long long t;
        char d;
        cin >> t >> d;
        incoming[dirIndex(d)].push_back({t, dirIndex(d), i});
    }

    array<size_t, 4> ptr{};
    array<queue<int>, 4> que;
    vector<long long> answer(n, -1);
    auto nextArrival = [&] {
        long long m = LLONG_MAX;
        for (int k = 0; k < 4; ++k) {
            if (ptr[k] < incoming[k].size()) {
                m = min(m, incoming[k][ptr[k]].time);
            }
        }
        return m;
    };
    long long now = 0;
    while (true) {
        bool hasWaiting = false;
        for (int k = 0; k < 4; ++k) if (!que[k].empty()) {
            hasWaiting = true; break;
        }
        if (!hasWaiting && [&] {
            for (int k = 0; k < 4; ++k) if (ptr[k] < incoming[k].size()) return false;
            return true;
        }()) break;
        if (!hasWaiting) now = nextArrival();
        for (int k = 0; k < 4; ++k) {
            while (ptr[k] < incoming[k].size() && incoming[k][ptr[k]].time == now) {
                que[k].push(incoming[k][ptr[k]++].idx);
            }
        }

        array<bool, 4> can{};
        for (int k = 0; k < 4; ++k) {
            can[k] = !que[k].empty() && que[(k + 1) % 4].empty();
        }
        bool any = false;
        for (bool v : can) if (v) { any = true; break; }
        if (any) {
            for (int k = 0; k < 4; ++k) if (can[k]) {
                int id = que[k].front(); que[k].pop();
                answer[id] = now;
            }
            ++now;
        } else {
            break;
        }
    }
    for (long long x : answer) cout << x << '\n';
    return 0;
}