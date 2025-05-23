#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--)
    {
        string s;
        cin >> s;

        int len = s.length();
        bool valid = true;
        int i = 0;

        while (i < len) {
            if (i + 1 < len) {
                string two_chars = s.substr(i, 2);
                if (two_chars == "AB" || two_chars == "BA") {
                    i += 2;
                    continue;
                }
            }

            if (s[i] == 'A') {
                i += 1;
                continue;
            }

            valid = false;
            break;
        }

        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}