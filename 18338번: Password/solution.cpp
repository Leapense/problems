#include <bits/stdc++.h>
using namespace std;

static constexpr int dx[4]{1, 0, -1, 0};
static constexpr int dy[4]{0, 1, 0, -1};

static int idir(char c) {
    return c == 'R' ? 0 : c == 'U' ? 1 : c == 'L' ? 2 : 3;
}

static uint64_t dfs(const string &s, int depth, int x, int y, uint16_t vis) {
    if (depth == static_cast<int>(s.size())) {
        return 1;
    }

    uint64_t res = 0;
    int d = idir(s[depth]);
    for (int step = 1; step <= 2; ++step) {
        int nx = x + dx[d] * step;
        int ny = y + dy[d] * step;
        if (nx < 0 || nx > 2 || ny < 0 || ny > 2) {
            break;
        }
        int midx = x + dx[d] * (step == 2);
        int midy = y + dy[d] * (step == 2);
        int midId = midy * 3 + midx;
        int endId = ny * 3 + nx;
        if (step == 2 && (vis & (1u << midId))) {
            continue;
        }
        if (vis & (1u << endId)) {
            continue;
        }

        uint16_t nvis = vis | (1u << endId);
        if (step == 2) {
            nvis |= (1u << midId);
        }

        res += dfs(s, depth + 1, nx, ny, nvis);
    }

    return res;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) {
        return 0;
    }

    uint64_t total = 0;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            uint16_t vis = 1u << (y * 3 + x);
            total += dfs(s, 0, x, y, vis);
        }
    }

    cout << total << '\n';
    return 0;
}