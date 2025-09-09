#include <stdio.h>
#include <string.h>

enum { MOD = 1000000007 };

static inline int addmod(int a, int b) { int s = a + b; if (s >= MOD) s -= MOD; return s; }
static inline int mulmod(long long a, long long b) { return (int)((a * b) % MOD); }

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    char buf[32];
    for (int i = 0; i < n; ++i) scanf("%31s", buf);

    static int dp[21+1][2][21+1][21+1];
    memset(dp, 0, sizeof(dp));

    dp[1][0][1][1] = 5;
    dp[1][1][1][1] = 11;

    for (int i = 1; i < n; ++i) {
        for (int last = 0; last < 2; ++last) {
            for (int run = 1; run <= m; ++run) {
                for (int best = 1; best <= m; ++best) {
                    int cur = dp[i][last][run][best];
                    if (!cur) continue;
                    {
                        int nlast = last;
                        int nrun = 1;
                        int nbest = best;
                        int w = (nlast == 0) ? 5 : 11;
                        int add = mulmod(cur, w);
                        dp[i+1][nlast][nrun][nbest] = addmod(dp[i+1][nlast][nrun][nbest], add);
                    }
                    {
                        int nlast = 1 - last;
                        int nrun = run + 1;
                        int nbest = (best > nrun ? best : nrun);
                        if (nbest <= m) {
                            int w = (nlast == 0) ? 5 : 11;
                            int add = mulmod(cur, w);
                            dp[i + 1][nlast][nrun][nbest] = addmod(dp[i + 1][nlast][nrun][nbest], add);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int last = 0; last < 2; ++last) {
        for (int run = 1; run <= m; ++run) {
            ans = addmod(ans, dp[n][last][run][m]);
        }
    }

    printf("%d\n", ans);
    return 0;
}