#include <bits/stdc++.h>
using namespace std;

static string toBinary(string dec) {
    if (dec == "0") {
        return "0";
    }

    string bin;
    while (dec != "0") {
        string next;
        next.reserve(dec.size());
        int carry = 0;
        for (char ch : dec) {
            int x = carry * 10 + (ch - '0');
            int q = x / 2;
            carry = x % 2;
            if (!next.empty() || q != 0) {
                next.push_back(char('0' + q));
            }
        }
        bin.push_back(char('0' + carry));
        dec = next.empty() ? "0" : next;
    }

    reverse(bin.begin(), bin.end());
    return bin;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while(t-- > 0) {
        string dec;
        cin >> dec;
        string s = toBinary(dec);
        int n = s.size();
        bool isOdd = (s.back() == '1');

        bool ok = false;
        if (isOdd) {
            ok = equal(s.begin(), s.begin() + n / 2, s.rbegin());
        } else {
            ok = true;
            for (int i = 0; i < n; ++i) {
                if (s[i] == s[n - 1 - i]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "TAK" : "NIE") << "\n";
    }

    return 0;
}