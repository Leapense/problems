#include <stdio.h>
#include <string.h>

typedef long long ll;
const ll MOD = 1000000009LL;

static ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }

    return r;
}

static ll inv(ll x) { return modpow(x, MOD - 2); }

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    const int MAXN = 100;
    static ll fac[101], ifac[101];
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[MAXN] = inv(fac[MAXN]);
    for (int i = MAXN; i >= 1; i--) ifac[i - 1] = ifac[i] * i % MOD;
    while (T--) {
        int n;
        scanf("%d", &n);
        static int p[1005];
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

        static int vis[1005];
        memset(vis, 0, sizeof(int) * (n + 2));

        int lens[1005], lc = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int u = i, len = 0;
                while (!vis[u]) {
                    vis[u] = 1;
                    u = p[u];
                    len++;
                }

                lens[lc++] = len;
            }
        }

        int c = lc;
        int m = n - c;

        ll ways = fac[m];
        for (int i = 0; i < lc; i++) {
            int L = lens[i];
            int idx = (L >= 1) ? (L - 1) : 0;
            ways = ways * ifac[idx] % MOD;
        }

        for (int i = 0; i < lc; i++) {
            int L = lens[i];
            if (L <= 1) continue;
            ways = ways * modpow(L, L - 2) % MOD;
        }

        printf("%lld\n", ways % MOD);
    }

    return 0;
}