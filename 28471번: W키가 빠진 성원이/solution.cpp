#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> g(N);
    for (int i = 0; i < N; ++i) cin >> g[i];

    int fr = -1, fc = -1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (g[i][j] == 'F') { fr = i; fc = j; }

    const int dx[7] = {-1,-1,0,0,1,1,1};
    const int dy[7] = {-1,1,-1,1,1,0,-1};

    vector<vector<char>> vis(N, vector<char>(N, 0));
    deque<pair<int,int>> q;
    q.emplace_back(fr, fc);
    vis[fr][fc] = 1;

    auto inb = [&](int r, int c) { return 0 <= r && r < N && 0 <= c && c < N; };

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop_front();
        for (int k = 0; k < 7; ++k) {
            int nr = r - dx[k];
            int nc = c - dy[k];
            if (!inb(nr, nc)) continue;
            if (g[nr][nc] == '#') continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            q.emplace_back(nr, nc);
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (g[i][j] == '.' && vis[i][j]) ++ans;

    cout << ans << "\n";
    return 0;
}