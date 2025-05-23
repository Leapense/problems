#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    int count = 0;

    int state = 0;

    for (char c : s) {
        if (state == 0) {
            if (c == 'o') state = 1;
        } else if (state == 1) {
            if (c == 'i') state = 2;
        } else if (state == 2) {
            if (c == 'j') {
                count++;
                state = 0;
            }
        }
    }

    if (count > 0) cout << count << "\n";
    else cout << "NIE\n";

    return 0;
}