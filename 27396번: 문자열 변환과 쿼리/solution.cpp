#include <bits/stdc++.h>
using namespace std;

inline int id(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return 26 + (c - 'a');
}

inline char ch(int v) {
    if (v < 26) return char('A' + v);
    return char('a' + (v - 26));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    int n;
    if (!(cin >> S >> n)) return 0;

    array<int, 52> p;
    iota(p.begin(), p.end(), 0);

    for (int qi = 0; qi < n; ++qi) {
        int t;
        cin >> t;
        if (t == 1) {
            char c1, c2;
            cin >> c1 >> c2;
            int a = id(c1), b = id(c2);
            for (int x = 0; x < 52; ++x) if (p[x] == a) p[x] = b;
        } else {
            for (char c : S) {
                int v = p[id(c)];
                cout << ch(v);
            }
            cout << "\n";
        }
    }

    return 0;
}