#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N)) return 0;
    cin >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int X;
    cin >> X;

    int startColor = grid[0][0];
    int goalColor = grid[N-1][M-1];
    if (startColor != goalColor) {
        cout << "DEAD\n";
        return 0;
    }

    vector<pair<int, int>> off;
    off.reserve((2 * X + 1) * (2 * X + 1));
    for (int dr = -X; dr <= X; ++dr) {
        for (int dc = -X; dc <= X; ++dc) {
            if (dr == 0 && dc == 0) continue;
            if (abs(dr) + abs(dc) <= X) off.emplace_back(dr, dc);
        }
    }

    vector<vector<char>> vis(N, vector<char>(M, 0));
    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.emplace(0, 0);

    auto inb = [&](int r, int c) {
        return (0 <= r && r < N && 0 <= c && c < M);
    };

    bool alive = false;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == N - 1 && c == M - 1) {
            alive = true;
            break;
        }

        for (auto [dr, dc] : off) {
            int nr = r + dr, nc = c + dc;
            if (!inb(nr, nc)) continue;
            if (vis[nr][nc]) continue;
            if (grid[nr][nc] != startColor) continue;
            vis[nr][nc] = 1;
            q.emplace(nr, nc);
        }
    }

    cout << (alive ? "ALIVE\n" : "DEAD\n");
    return 0;
}