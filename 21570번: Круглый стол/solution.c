#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 1000
#define MAX_L 2000
#define NEG   -1000000

typedef struct {
    short prevBoy;
    unsigned char prevL2;
    unsigned char prevL1;
    unsigned char ch;
} Parent;

static inline int active(unsigned char l, unsigned char m, unsigned char r) {
    if (m == 0) return l == 1 && r == 1;
    return (l ^ r) == 1;
}

int main(void) {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    const int L = m + n;

    static int    dp[MAX_L + 1][MAX_M + 1][4];
    static Parent par[MAX_L + 1][MAX_M + 1][4];

    char bestStr[MAX_L + 1];
    int  bestScore = NEG;

    for (unsigned char f = 0; f < 2; ++f) {
        for (unsigned char s = 0; s < 2; ++s) {
            int boys0 = (f == 0) + (s == 0);
            int girls0 = (f == 1) + (s == 1);
            if (boys0 > m || girls0 > n) continue;

            /* 배열 전체 초기화 – 바로 버그 픽 */
            for (int i = 0; i <= L; ++i)
                for (int b = 0; b <= m; ++b)
                    for (int st = 0; st < 4; ++st)
                        dp[i][b][st] = NEG;

            const int st0 = (f << 1) | s;
            dp[2][boys0][st0] = 0;
            par[2][boys0][st0] = (Parent){ .prevBoy = -1 };

            for (int pos = 2; pos < L; ++pos) {
                for (int b = 0; b <= m; ++b) {
                    for (int st = 0; st < 4; ++st) {
                        if (dp[pos][b][st] == NEG) continue;
                        unsigned char l2 = st >> 1;
                        unsigned char l1 = st & 1;
                        for (unsigned char c = 0; c < 2; ++c) {
                            int nb = b + (c == 0);
                            int ng = (pos + 1) - nb;
                            if (nb > m || ng > n) continue;
                            int gain   = active(l2, l1, c);
                            int nstate = (l1 << 1) | c;
                            if (dp[pos + 1][nb][nstate] < dp[pos][b][st] + gain) {
                                dp[pos + 1][nb][nstate] = dp[pos][b][st] + gain;
                                par[pos + 1][nb][nstate] = (Parent){
                                    .prevBoy = b, .prevL2 = l2, .prevL1 = l1, .ch = c
                                };
                            }
                        }
                    }
                }
            }

            for (int st = 0; st < 4; ++st) {
                if (dp[L][m][st] == NEG) continue;
                unsigned char l2 = st >> 1;
                unsigned char l1 = st & 1;
                int add = active(l2, l1, f) + active(l1, f, s);
                int score = dp[L][m][st] + add;
                if (score > bestScore) {
                    bestScore = score;

                    /* 역추적 */
                    char res[MAX_L + 1];
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
                    res[L] = '\0';
                    memcpy(bestStr, res, L + 1);
                }
            }
        }
    }
    printf("%s\n", bestStr);
    return 0;
}