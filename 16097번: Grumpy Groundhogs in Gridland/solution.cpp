#include <bits/stdc++.h>
using namespace std;

struct Interval { unsigned a, b; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned n;
        cin >> n;
        vector<Interval> v(n);
        for (auto &i : v) {
            cin >> i.a >> i.b;
        }
        sort(v.begin(), v.end(), [](auto &x, auto &y){ return x.a < y.a; });
        vector<unsigned> st;
        st.reserve(n);
        unsigned maxDepth = 0;
        bool possible = true;
        for (auto &iv : v) {
            while (!st.empty() && v[st.back()].b < iv.a) {
                st.pop_back();
            }
            if (!st.empty() && iv.b > v[st.back()].b) {
                possible = false;
                break;
            }
            st.push_back(&iv - v.data());
            maxDepth = max(maxDepth, (unsigned)st.size());
        }
        if (!possible) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << 2 * maxDepth - 1 << "\n";
        }
    }
    return 0;
}