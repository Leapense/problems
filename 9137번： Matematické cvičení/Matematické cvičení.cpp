#include <bits/stdc++.h>
using namespace std;

static inline int val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

static inline char digitChar(int v) {
    if (v < 10) return (char)('0' + v);
    return (char)('A' + (v - 10));
}

static string addBase(const string &a, const string &b, int base) {
    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    string res;

    while(i >= 0 || j >= 0 || carry) {
        int x = 0, y = 0;
        if (i >= 0) x = val(a[i--]);
        if (j >= 0) y = val(b[j--]);
        int s = x + y + carry;
        carry = s / base;
        s = s % base;
        res.push_back(digitChar(s));
    }
    reverse(res.begin(), res.end());
    return res;
}

static string addBaseOne(const string &a, const string &b) {
    if (a == "0" && b == "0") return "0";
    int cntA = (a == "0") ? 0 : (int)a.size();
    int cntB = (b == "0") ? 0 : (int)b.size();
    int total = cntA + cntB;
    if (total == 0) return "0";
    return string(total, '1');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int z; cin >> z;

        if (!cin || z == 0) break;
        
        string x, y; cin >> x >> y;
        if (z == 1) {
            string sum = addBaseOne(x, y);
            cout << x << " + " << y << " = " << sum << "\n";
        } else {
            string sum = addBase(x, y, z);
            cout << x << " + " << y << " = " << sum << "\n";
        }
    }

    return 0;
}