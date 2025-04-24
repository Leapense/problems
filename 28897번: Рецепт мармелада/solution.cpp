#include <bits/stdc++.h>
using namespace std;

string solve(istream& in) {
    int n, m;
    in >> n >> m;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i) in >> b[i];
    ostringstream out;
    bool first = true;
    for (int i = 1; i <= m; ++i) {
        int cnt = b[i] - b[i - 1];
        while (cnt--) {
            if (!first) out << ' ';
            first = false;
            out << i;
        }
    }
    return out.str();
}

#ifndef UNIT_TEST
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve(cin) << '\n';
    return 0;
}
#endif
