#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    if (!getline(cin, line)) return 0;
    string s;
    s.reserve(line.size());
    for (char c : line) if (c == '(' || c == ')') s.push_back(c);
    vector<int> st;
    st.reserve(s.size() + 2);
    long long total = 0;
    for (char c : s) {
        if (c == '(') {
            st.push_back(0);
        } else {
            int t = st.back();
            st.pop_back();
            int h = (t == 0) ? 1 : t + 1;
            total += h;
            if (!st.empty()) {
                if (st.back() < h) st.back() = h;
            }
        }
    }

    cout << total << '\n';
    return 0;
}