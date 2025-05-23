#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        string S;
        cin >> S;

        int mapping[256];
        for (int i = 0; i < 256; i++) mapping[i] = -1;

        vector<char> unique_symbols;

        for (char c : S) {
            if (mapping[c] == -1) {
                unique_symbols.push_back(c);
                mapping[c] = -2;
            }
        }

        mapping[unique_symbols[0]] = 1;

        int next_digit = 0;

        if (unique_symbols.size() > 1) {
            mapping[unique_symbols[1]] = 0;
            next_digit = 2;
        } else {
            next_digit = 2;
        }

        for (int i = 2; i < unique_symbols.size(); i++) {
            while (next_digit == 1 || next_digit == 0) {
                next_digit++;
            }
            mapping[unique_symbols[i]] = next_digit;
            next_digit++;
        }

        int base = max(2, (int)unique_symbols.size());

        ll V = 0;
        for (char c : S) {
            V = V * base + mapping[c];
        }

        cout << "Case #" << test << ": " << V << "\n";
    }

    return 0;
}