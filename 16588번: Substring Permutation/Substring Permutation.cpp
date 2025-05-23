#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string S, P;
    cin >> S >> P;

    int freq_S[26] = {0};
    int freq_P[26] = {0};

    for (char c : S) {
        freq_S[c - 'a']++;
    }

    for (char c : P) {
        freq_P[c - 'a']++;
    }

    bool ok = true;

    for (int i = 0; i < 26; i++) {
        if (freq_P[i] > freq_S[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}