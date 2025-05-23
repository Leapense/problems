#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string sort_descending(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    cin.exceptions(cin.failbit);

    int t;

    cin >> t;
    cin.ignore();

    while(t--) {
        string s;
        while (getline(cin, s)) {
            if (s.empty()) continue;
            else break;
        }

        s = sort_descending(s);

        int n = s.size();
        string a_str = s.substr(0, n - 1);
        string b_str = s.substr(n - 1, 1);

        ll a = stoll(a_str);
        ll b = stoll(b_str);

        ll total = a + b;

        cout << total << "\n";
    }

    return 0;
}