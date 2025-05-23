#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        string S;
        cin >> S;

        vector<char> unique_symbols;
        bool seen[256];

        memset(seen, false, sizeof(seen));

        for (char c : S) {
            if (!seen[c]) {
                unique_symbols.push_back(c);
                seen[c] = true;
            }
        }

        int mapping[256];
        memset(mapping, -1, sizeof(mapping));

        if (unique_symbols.size() >= 1) {
            mapping[unique_symbols[0]] = 1;
        }

        if (unique_symbols.size() >= 2) {
            mapping[unique_symbols[1]] = 0;
        }

        int next_digit = 2;

        for(int i = 2; i < unique_symbols.size(); i++) {
            mapping[unique_symbols[i]] = next_digit;
            next_digit++;
        }

        int base = max((int)unique_symbols.size(), 2);

        ull value = 0;
        for (char c : S) {
            value = value * base + mapping[c];
        }

        cout << "Case #" << test << ": " << value << "\n";
    }

    return 0;
}