#include <bits/stdc++.h>
using namespace std;

static bool reachable(uint64_t x, uint64_t y) {
    if (y == 0) {
        return true;
    }

    for (uint32_t s = 0; s <= 32; s++) {
        for (uint32_t m = 0; m <= 32 - s; m++) {
            uint64_t mask = (m == 0) ? 0ULL : ((1ULL << m) - 1ULL);
            uint64_t seg = (x >> s) & mask;
            for (uint32_t p = 0; p <= 32 - m; p++) {
                uint64_t cand = seg << p;
                if (cand == y) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) {
        return 0;
    }

    while (t--) {
        uint64_t x, y;
        cin >> x >> y;
        x &= 0xFFFFFFFFULL;
        y &= 0xFFFFFFFFULL;
        bool ok = reachable(x, y);
        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}