#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    long long A, B;
    if (!(cin >> N >> M >> A >> B)) return 0;

    vector<int> diff(N + 2, 0);
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        L = max(1, L);
        R = min(N - 1, R);
        if (L <= R) {
            diff[L] += 1;
            diff[R + 1] -= 1;
        }
    }

    vector<char> forbid(N + 1, false);
    int run = 0;
    for (int i = 1; i <= N - 1; ++i) {
        run += diff[i];
        forbid[i] = (run > 0);
    }
    forbid[0] = false;

    auto next_state = [&](int x, long long add) -> optional<int> {
        long long y = x + add;
        if (y > N) return nullopt;
        int yi = (int)y;
        if (yi >= 1 && yi <= N - 1 && forbid[yi]) return 0;
        return yi;
    };

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (long long add : {A, B}) {
            auto ns = next_state(x, add);
            if (!ns.has_value()) continue;
            int y = ns.value();
            if (dist[y] != -1) continue;
            dist[y] = dist[x] + 1;
            if (y == N) {
                cout << dist[y] << "\n";
                return 0;
            }

            q.push(y);
        }
    }

    cout << -1 << "\n";
    return 0;
}