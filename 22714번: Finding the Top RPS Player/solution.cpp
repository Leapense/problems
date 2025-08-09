#include <bits/stdc++.h>
using namespace std;

static long long solve_case(int n, int m) {
    if (m <= 0) return 0;
    if (m == 1) return 1;

    long long turns = 0;
    vector<int> g(m + 1), nxt(m + 1);
    g[0] = n;
    while (true) {
        if (g[m] > 0) return turns;
        fill(nxt.begin(), nxt.end(), 0);
        int addZero = 0;
        int matches0 = g[0] / 2;
        nxt[1] += matches0;
        addZero += matches0 + (g[0] % 2);
        for (int k = 1; k < m; ++k) {
            int matches = g[k] / 2;
            nxt[k + 1] += matches;
            addZero += matches;
            if (g[k] % 2) nxt[k] += 1;
        }

        nxt[0] += addZero;
        ++turns;
        g.swap(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, caseNo = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        cout << "Case " << caseNo++ << ": " << solve_case(n, m) << "\n";
    }

    return 0;
}