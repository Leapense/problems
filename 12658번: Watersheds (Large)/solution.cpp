#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100;
int H, W;
int alt[MAX][MAX];
pair<int, int> flow_to[MAX][MAX];
pair<int, int> sink_of[MAX][MAX];

void compute_flow() {
    static int dr[4] = {-1, 0, 0, +1};
    static int dc[4] = {0, -1, +1, 0};
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            int base = alt[r][c];
            int best_alt = base;
            int best_d = -1;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (0 <= nr && nr < H && 0 <= nc && nc < W) {
                    int h = alt[nr][nc];
                    if (h < best_alt) {
                        best_alt = h;
                        best_d = d;
                    }
                }
            }

            if (best_d < 0) {
                flow_to[r][c] = {r, c};
            } else {
                flow_to[r][c] = {r + dr[best_d], c + dc[best_d]};
            }
        }
    }
}

pair<int, int> find_sink(int r, int c) {
    auto& s = sink_of[r][c];
    if (s.first >= 0) {
        return s;
    }

    auto [nr, nc] = flow_to[r][c];
    if (nr == r && nc == c) {
        s = {r, c};
    } else {
        s = find_sink(nr, nc);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> H >> W;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> alt[i][j];
                sink_of[i][j] = {-1, -1};
            }
        }

        compute_flow();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                find_sink(i, j);
            }
        }

        array<array<char, MAX>, MAX> label_map{};
        char next_label = 'a';
        cout << "Case #" << tc << ":\n";
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                auto [sr, sc] = sink_of[i][j];
                if (label_map[sr][sc] == '\0') {
                    label_map[sr][sc] = next_label++;
                }

                cout << label_map[sr][sc] << (j + 1 < W ? ' ' : '\n');
            } 
        }
    }

    return 0;
}