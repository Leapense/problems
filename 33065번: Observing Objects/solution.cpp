#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    const int64_t total = 1LL * N * M;
    vector<uint32_t> grid;
    grid.reserve(total);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int R, G, B;
            cin >> R >> G >> B;
            uint32_t key = (uint32_t(R) << 16) | (uint32_t(G) << 8) | uint32_t(B);
            grid.push_back(key);
        }
    }

    vector<uint8_t> vis(total, 0);
    vector<int> q;
    q.reserve(1 << 20);
    auto idx = [M](int r, int c) {return r * M + c;};

    const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    uint32_t components = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int start = idx(r, c);
            if (vis[start]) continue;

            ++components;
            uint32_t color = grid[start];

            q.clear();
            q.push_back(start);
            vis[start] = 1;

            for (size_t h = 0; h < q.size(); ++h) {
                int v = q[h];
                int vr = v / M, vc = v % M;
                for (int k = 0; k < 8; ++k) {
                    int nr = vr + dr[k], nc = vc + dc[k];
                    if ((unsigned)nr < (unsigned)N && (unsigned)nc < (unsigned)M) {
                        int ni = idx(nr, nc);
                        if (!vis[ni] && grid[ni] == color) {
                            vis[ni] = 1;
                            q.push_back(ni);
                        }
                    }
                }
            }
        }
    }

    cout << components << '\n';
    return 0;
}