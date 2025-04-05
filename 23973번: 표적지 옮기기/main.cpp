#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 2500;
static constexpr int MAXM = 2500;

int N, M;
vector<pair<int, int>> hits;

static uint8_t center_score_count[MAXN][MAXM][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    hits.reserve(100000);

    for (int r = 0; r < N; r++) {
        string row;
        cin >> row;
        for (int c = 0; c < M; c++) {
            if (row[c] == '1') {
                hits.emplace_back(r, c);
            }
        }
    }

    vector<tuple<int, int, int>> offsets;
    offsets.reserve(361);
    for (int r = 0; r < 19; r++) {
        for (int c = 0; c < 19; c++) {
            int d = max(abs(r - 9), abs(c - 9));
            int ring = 10 - d;
            if (ring >= 1 && ring <= 10) {
                offsets.emplace_back(r - 9, c - 9, ring);
            }
        }
    }

    for (const auto &[x, y] : hits) {
        for (const auto &[dr, dc, ring] : offsets) {
            int R = x - dr;
            int C = y - dc;

            if (R >= 0 && R < N && C >= 0 && C < M) {
                uint8_t &cnt = center_score_count[R][C][ring - 1];
                if (cnt < 2) cnt++;
            }
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            bool valid = true;
            for (int k = 0; k < 10; k++) {
                if (center_score_count[r][c][k] != 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << r << " " << c << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
