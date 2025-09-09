#include <bits/stdc++.h>
using namespace std;

static constexpr long long MOD = 1'000'000'007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    string s;

    for (int i = 0; i < n; ++i) cin >> s;

    auto make4 = [&](int a, int b, int c, int d) {
        return vector(a, vector(b, vector(c, vector<long long>(d, 0))));
    };

    auto dp = make4(n+1, 2, m+1, m+1);

    dp[1][0][1][1] = 5;
    dp[1][1][1][1] = 11;

    auto ways = [](int t)->long long { return t == 0 ? 5 : 11; };
    for(int i = 1; i < n; ++i) {
        for (int last = 0; last < 2; ++last) {
            for (int run = 1; run <= m; ++run) {
                for (int best = 1; best <= m; ++best) {
                    long long cur = dp[i][last][run][best];
                    if (!cur) continue;
                    {
                        int nlast = last;
                        int nrun = 1;
                        int nbest = best;
                        long long add = (cur * ways(nlast)) % MOD;
                        dp[i+1][nlast][nrun][nbest] += add;
                        if (dp[i+1][nlast][nrun][nbest] >= MOD) dp[i+1][nlast][nrun][nbest] -= MOD;
                    }
                    {
                        int nlast = 1 - last;
                        int nrun = run + 1;
                        int nbest = max(best, nrun);
                        if (nbest <= m) {
                            long long add = (cur * ways(nlast)) % MOD;
                            dp[i+1][nlast][nrun][nbest] += add;
                            if (dp[i+1][nlast][nrun][nbest] >= MOD) dp[i+1][nlast][nrun][nbest] -= MOD;
                        }
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int last = 0; last < 2; ++last) {
        for (int run = 1; run <= m; ++run) {
            ans += dp[n][last][run][m];
            if (ans >= MOD) ans -= MOD;
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}