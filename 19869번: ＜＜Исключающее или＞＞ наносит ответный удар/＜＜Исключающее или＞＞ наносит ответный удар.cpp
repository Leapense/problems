#include <bits/stdc++.h>
using namespace std;

string toString128(__int128 x) {
    if (x == 0) return "0";
    bool neg = (x < 0);
    if (neg) x = -x;
    string s;

    while (x > 0) {
        s.push_back(char('0' + int(x % 10)));
        x /= 10;
    }

    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        long long a0, n0;
        cin >> a0 >> n0;

        __int128 a = (__int128) a0, n = (__int128) n0;
        long long k = (long long)(a0 / n0);
        __int128 best = -1;

        for (int i = -1; i <= 2; i++) {
            long long x = k + i;
            if (x < 0) continue;
            __int128 m = (__int128)x * n;
            __int128 b = a ^ m;
            if (best < 0 || b < best) best = b;
        }

        cout << toString128(best) << "\n";
    }

    return 0;
}