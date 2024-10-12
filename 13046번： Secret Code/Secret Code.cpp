#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    string s;

    cin >> s;

    bool present[256] = {false};

    for (char c : s) {
        present[c] = true;
    }

    int n;
    cin >> n;

    while(n--) {
        string t;
        cin >> t;

        int a = 0, total = 0;

        for (int i = 0; i < s.size(); i++) {
            if (t[i] == s[i]) a++;
            if (present[t[i]]) total++;
        }

        cout << a << " " << (total - a) << "\n";
    }

    return 0;
}