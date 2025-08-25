#include <bits/stdc++.h>
using namespace std;

struct P { int r, c; };

static vector<P> rotate90(const vector<P>& pts, int N) {
    vector<P> out;
    out.reserve(pts.size());
    for (auto [r, c] : pts) out.push_back({c, N - 1 - r});
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> stainGrid(N), stickerGrid(N);
    for (int i = 0; i < N; ++i) cin >> stainGrid[i];
    for (int i = 0; i < N; ++i) cin >> stickerGrid[i];

    vector<P> A, B;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (stainGrid[r][c] == '#') A.push_back({r, c});
            if (stickerGrid[r][c] == '#') B.push_back({r, c});
        }
    }

    int bestOverlap = 0;
    vector<P> cur = B;
    for (int rot = 0; rot < 4; ++rot) {
        int S = 2 * N + 1;
        vector<vector<int>> cnt(S, vector<int>(S, 0));
        for (const auto& a : A) {
            for (const auto& b : cur) {
                int dx = a.r - b.r;
                int dy = a.c - b.c;
                cnt[dx + N][dy + N] += 1;
            }
        }
        for (int i = 0; i < S; ++i)
            for (int j = 0; j < S; ++j)
                bestOverlap = max(bestOverlap, cnt[i][j]);

        cur = rotate90(cur, N);
    }

    int answer = static_cast<int>(A.size()) - bestOverlap;
    cout << answer << '\n';
    return 0;
}