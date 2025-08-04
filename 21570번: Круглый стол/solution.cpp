#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_M = 1000;
constexpr int MAX_L = 2000;
constexpr int NEG   = -1'000'000;

struct Parent {
    short prevBoy;
    uint8_t prevL2;
    uint8_t prevL1;
    uint8_t ch;
};

static int active(bool l, bool m, bool r) {
    if (!m) return l && r;
    return (l ^ r) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    const int L = m + n;

    static int    dp[MAX_L + 1][MAX_M + 1][4];
    static Parent par[MAX_L + 1][MAX_M + 1][4];

    string best;
    int bestScore = NEG;

    for (uint8_t f = 0; f < 2; ++f) {
        for (uint8_t s = 0; s < 2; ++s) {
            int boys0  = (f == 0) + (s == 0);
            int girls0 = (f == 1) + (s == 1);
            if (boys0 > m || girls0 > n) continue;

            for (int i = 0; i <= L; ++i)
                for (int b = 0; b <= m; ++b)
                    for (int st = 0; st < 4; ++st)
                        dp[i][b][st] = NEG;

            int st0 = (f << 1) | s;
            dp[2][boys0][st0] = 0;
            par[2][boys0][st0] = { -1, 0, 0, 0 };

            for (int pos = 2; pos < L; ++pos) {
                for (int b = 0; b <= m; ++b) {
                    for (int st = 0; st < 4; ++st) {
                        if (dp[pos][b][st] == NEG) continue;
                        uint8_t l2 = st >> 1;
                        uint8_t l1 = st & 1;
                        for (uint8_t c = 0; c < 2; ++c) {
                            int nb = b + (c == 0);
                            int ng = (pos + 1) - nb;
                            if (nb > m || ng > n) continue;
                            int gain   = active(l2, l1, c);
                            int nstate = (l1 << 1) | c;
                            if (dp[pos + 1][nb][nstate] < dp[pos][b][st] + gain) {
                                dp[pos + 1][nb][nstate] = dp[pos][b][st] + gain;
                                par[pos + 1][nb][nstate] = { static_cast<short>(b), l2, l1, c };
                            }
                        }
                    }
                }
            }

            for (int st = 0; st < 4; ++st) {
                if (dp[L][m][st] == NEG) continue;
                uint8_t l2 = st >> 1;
                uint8_t l1 = st & 1;
                int add = active(l2, l1, f) + active(l1, f, s);
                int score = dp[L][m][st] + add;
                if (score > bestScore) {
                    bestScore = score;
                    string res(L, '?');
                    int pos = L;
                    int b   = m;
                    int cur = st;
                    while (pos > 2) {
                        Parent p = par[pos][b][cur];
                        res[pos - 1] = p.ch == 0 ? 'B' : 'G';
                        b   = p.prevBoy;
                        cur = (p.prevL2 << 1) | p.prevL1;
                        --pos;
                    }
                    res[0] = f == 0 ? 'B' : 'G';
                    res[1] = s == 0 ? 'B' : 'G';
                    best = move(res);
                }
            }
        }
    }
    cout << best << '\n';
    return 0;
}