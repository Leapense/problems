#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000009LL;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;

    while (e > 0) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }

    return r;
}

long long inv(long long x) { return modpow(x, MOD - 2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    
    const int MAXN = 100;
    vector<long long> fac(MAXN + 1, 1), ifac(MAXN + 1, 1);
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[MAXN] = inv(fac[MAXN]);
    for (int i = MAXN; i > 0; i--) ifac[i - 1] = ifac[i] * i % MOD;

    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<int> vis(n + 1, 0);
        vector<int> lens;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int u = i, len = 0;
                while (!vis[u]) {
                    vis[u] = 1;
                    u = p[u];
                    len++;
                }
                lens.push_back(len);
            }
        }

        int c = (int)lens.size();
        int m = n - c;

        long long ways = 1;

        ways = fac[m];
        for (int L: lens) {
            ways = ways * ifac[max(0, L-1)] % MOD;
        }
        for (int L: lens) {
            if (L <= 1) continue;
            ways = ways * modpow(L, L-2) % MOD;
        }

        cout << ways % MOD << "\n";
    }

    return 0;
}