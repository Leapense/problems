#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r, k;
    cin >> n >> r >> k;
    vector<vector<vector<int>>> dist(1001, vector<vector<int>>(2, vector<int>(1001, -1)));

    queue<array<int, 3>> q;

    int startVisited = (k == 0 ? 1 : 0);

    dist[0][startVisited][0] = 0;
    q.push({0, startVisited, 0});
    int ans = INT_MAX;

    while (!q.empty()) {
        auto [f, v, s] = q.front();
        q.pop();

        int cost = dist[f][v][s];

        if (f == r && v == 1 && s >= n) {
            ans = min(ans, cost + r);
            break;
        }

        for (int nf : {f - 1, f + 1}) {
            if (nf < 0 || nf > 1000) continue;
            int ns = (s < n ? s + 1 : n);
            int nv = (v == 1 ? 1 : (nf == k ? 1 : 0));

            if (dist[nf][nv][ns] == -1) {
                dist[nf][nv][ns] = cost + 1;
                q.push({nf, nv, ns});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}