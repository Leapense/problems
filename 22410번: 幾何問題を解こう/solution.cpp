#include <bits/stdc++.h>
using namespace std;

static uint64_t gcd_u64(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t p, q;
    if (!(cin >> p >> q)) return 0;
    uint64_t g = gcd_u64(p, q);
    uint64_t r = q / g;
    if (r == 1) {
        cout << 2 << "\n";
        return 0;
    }

    uint64_t ans = 1;
    for (uint64_t d = 2; d * d <= r; ++d) {
        if (r % d == 0) {
            ans *= d;
            while (r % d == 0) r /= d;
        }
    }

    if (r > 1) ans *= r;
    cout << ans << "\n";
    return 0;
}