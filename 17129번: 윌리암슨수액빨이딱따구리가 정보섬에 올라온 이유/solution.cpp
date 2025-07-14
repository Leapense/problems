#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<string> a(n);
    for (auto &row : a) cin >> row;

    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '2') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<int> dist(n * m, -1);
    deque<pair<int, int>> q;
    q.emplace_back(sx, sy);
    dist[sx * m + sy] = 0;

    array<int, 4> dx{1, -1, 0, 0};
    array<int, 4> dy{0, 0, 1, -1};

    array<bool, 3> found{false, false, false};
    int best = n * m + 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        int d = dist[x * m + y];
        char c = a[x][y];
        if (c >= '3' && c <= '5') {
            int idx = c - '3';
            if (!found[idx]) {
                found[idx] = true;
                best = min(best, d);
            }
        }

        if (found[0] && found[1] && found[2]) break;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int ni = nx * m + ny;
            if (dist[ni] != -1) continue;
            if (a[nx][ny] == '1') continue;
            dist[ni] = d + 1;
            q.emplace_back(nx, ny);
        }
    }

    if (best <= n * m) {
        cout << "TAK\n" << best << "\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}