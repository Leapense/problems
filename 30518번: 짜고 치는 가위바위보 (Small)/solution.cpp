#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1'000'000'007LL;
enum Move { R=0, P=1, S=2, NONE=3 };
enum Res { DRAW=0, LWIN=1, LLOSE=2, START=3 };

int toId(char c) { return c == 'R' ? R : c == 'P' ? P : S; }

int outcome(int L, int sm) {
    if (L == sm) return DRAW;
    int beats[3] = {S, R, P};
    return (beats[L] == sm) ? LWIN : LLOSE;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string L0s, Sstr;
    if (!(cin >> L0s)) return 0;
    cin >> Sstr;
    int n = (int)Sstr.size();
    int L0 = toId(L0s[0]);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = toId(Sstr[i]);

    static long long dp[21][4][4];
    memset(dp, 0, sizeof(dp));
    dp[0][NONE][START] = 1;

    for (int pos = 0; pos < n; ++pos) {
        for (int last = 0; last < 4; ++last) {
            for (int prev = 0; prev < 4; ++prev) {
                long long cur = dp[pos][last][prev];
                if (!cur) continue;

                dp[pos+1][last][prev] = (dp[pos+1][last][prev] + cur) % MOD;

                int sm = a[pos];
                int L = (last == NONE ? L0 : last);
                int curRes = outcome(L, sm);
                if (prev == LWIN && curRes == DRAW) {

                } else {
                    dp[pos+1][sm][curRes] = (dp[pos+1][sm][curRes] + cur) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int last = 0; last < 3; ++last) {
        for (int prev = 0; prev < 4; ++prev) {
            ans = (ans + dp[n][last][prev]) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}