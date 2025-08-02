#include "testlib.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(1, 100);
    println(t);

    const double PROB_SPECIAL = 0.15;

    for (int tc = 0; tc < t; ++tc) {
        int h = rnd.next(1, 100);
        int w = rnd.next(1, 100);
        println(h, w);

        vector<string> g(h, string(w, '.'));

        vector<pair<int, int>> pos;
        for (int r = 0; r < h; ++r) {
            for (int c = 1; c + 1 < w; ++c) {
                pos.push_back({r, c});
            }
        }

        shuffle(pos.begin(), pos.end());

        auto clearAround = [&](int r, int c) {
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= h || nc < 0 || nc >= w) {
                        continue;
                    }
                    if (g[nr][nc] != '.') return false;
                }
            }
            return true;
        };

        int gateCnt = 0;
        for (auto [r, c] : pos) {
            if (!clearAround(r, c)) continue;
            if (rnd.next(0.0, 1.0) < PROB_SPECIAL) {
                if (rnd.next(0, 1) == 0) {
                    g[r][c] = '*';
                } else {
                    g[r][c] = char('1' + rnd.next(0, 8));
                    ++gateCnt;
                }
            }
        }

        if (gateCnt == 0) {
            for (auto [r, c] : pos) {
                if (clearAround(r, c)) {
                    g[r][c] = char('1' + rnd.next(0, 8));
                    break;
                }
            }
        }

        for (auto &row : g) println(row);
    }

    return 0;
}