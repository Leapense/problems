#include <bits/stdc++.h>
using namespace std;
static constexpr int MOD = 1000000007;

int modpow (long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }

    return int(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;

    while (n--) {
        cin >> s;
        int len = s.size(), m = len / 2;
        long long q = 0;
        for (char c : s) if (c == '?') q++;
        long long valid = 1;
        for (int i = 0; i < m; i++) {
            char c1 = s[i], c2 = s[i + m];
            if (c1 == '?' && c2 == '?') {
                valid = (valid * 2) % MOD;
            } else if (c1 != '?' && c2 != '?') {
                if (c1 != c2) {
                    valid = 0;
                    break;
                }
            }
        }

        long long total = modpow(2, q);
        cout << (total - valid + MOD) % MOD << "\n";
    }

    return 0;
}