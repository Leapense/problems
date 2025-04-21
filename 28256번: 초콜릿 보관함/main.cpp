#include <bits/stdc++.h>
using namespace std;

void solve(istream& in, ostream& out) {
    int T;
    in >> T;
    while (T--) {
        vector<string> g(3);
        in >> g[0] >> g[1] >> g[2];

        int n;
        in >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) in >> a[i];
        vector<vector<bool>> vis(3, vector<bool>(3));

        vector<int> comps;

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            if (!vis[i][j] && g[i][j] == 'O') {
                int cnt = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;

                while(!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    cnt++;
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
                        if (nx == 1 && ny == 1) continue;

                        if (!vis[nx][ny] && g[nx][ny] == 'O') {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                comps.push_back(cnt);
            }
        }
        sort(comps.begin(), comps.end());
        if (comps.size() == a.size() && comps == a) out << "1\n"; else out << "0\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
