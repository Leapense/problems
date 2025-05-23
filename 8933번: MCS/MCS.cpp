#include <bits/stdc++.h>
using namespace std;

struct Composition {
    int A, G, C, T;
    bool operator<(const Composition &other) const {
        if (A != other.A) return A < other.A;
        if (G != other.G) return G < other.G;
        if (C != other.C) return C < other.C;
        return T < other.T;
    }

    bool operator==(const Composition &other) const {
        return A == other.A && G == other.G && C == other.C && T == other.T;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int k;
        cin >> k;
        
        string W;
        cin >> W;

        int n = (int)W.size();
        if (k > n) {
            cout << 0 << "\n";
            continue;
        }

        Composition comp = {0, 0, 0, 0};

        auto addChar = [&](char ch) {
            if (ch == 'A') comp.A++;
            else if (ch == 'G') comp.G++;
            else if (ch == 'C') comp.C++;
            else if (ch == 'T') comp.T++;
        };

        auto removeChar = [&](char ch) {
            if (ch == 'A') comp.A--;
            else if(ch == 'G') comp.G--;
            else if(ch == 'C') comp.C--;
            else if(ch == 'T') comp.T--;
        };

        for (int i = 0; i < k; i++) {
            addChar(W[i]);
        }

        map<Composition, int> freq;
        freq[comp] = 1;

        for (int i = k; i < n; i++) {
            addChar(W[i]);
            removeChar(W[i - k]);
            freq[comp]++;
        }

        int ans = 0;
        for (auto &it : freq) {
            if (it.second > ans) ans = it.second;
        }

        cout << ans << "\n";
    }

    return 0;
}