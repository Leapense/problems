#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int MOD = 1000000007;

int modpow (long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }

    return (int) res;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char *s = (char *)malloc(200005);
    for (int ti = 0; ti < n; ti++) {
        scanf("%s", s);
        int len = strlen(s);
        int m = len / 2;
        long long q = 0;
        for (int i = 0; i < len; i++) if (s[i] == '?') q++;
        long long valid = 1;
        for (int i = 0; i < m; i++) {
            char c1 = s[i], c2 = s[i + m];
            if (c1 == '?' && c2 == '?') {
                valid = (valid * 2) % MOD;
            } else if (c1 == '?' || c2 == '?') {

            } else if (c1 != c2) {
                valid = 0;
                break;
            }
        }

        long long total = modpow(2, q);
        long long ans = (total - valid + MOD) % MOD;
        printf("%lld\n", ans);
    }

    free(s);
    return 0;
}