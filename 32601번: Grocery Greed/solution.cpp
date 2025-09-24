#include <bits/stdc++.h>
using namespace std;

static long long parse_cents(const string& s) {
    long long euros = 0;
    size_t i = 0;
    while (i < s.size() && s[i] != '.') {
        euros = euros * 10 + (s[i] - '0');
        ++i;
    }

    long long cents = euros * 100;
    if (i < s.size() && s[i] == '.') {
        int c1 = (i + 1 < s.size() ? s[i + 1] - '0' : 0);
        int c2 = (i + 2 < s.size() ? s[i + 2] - '0' : 0);
        cents += c1 * 10 + c2;
    }

    return cents;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    long long S = 0;
    long long c[5] = {0,0,0,0,0};
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        long long x = parse_cents(s);
        S += x;
        c[x % 5]++;
    }

    long long D = 0;
    D += 1 * c[1];
    D += 2 * c[2];

    long long pair = min(c[3], c[4]);
    D += 2 * pair;
    c[3] -= pair;
    c[4] -= pair;

    D += 2 * (c[4] / 3);
    c[4] %= 3;

    D += 1 * (c[3] / 2);
    c[3] %= 2;

    long long ans = S - D;
    cout << (ans / 100) << '.' << setw(2) << setfill('0') << (ans % 100) << "\n";
    return 0;
}