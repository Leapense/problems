#include <bits/stdc++.h>
using namespace std;

static int gcd_int(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    if (!(cin >> H >> W)) return 0;
    vector<string> G(H);
    for (int r = 0; r < H; ++r) cin >> G[r];

    int ig = 0;
    for (int r = 0; r < H; ) {
        int s = r + 1;
        while (s < H && G[s] == G[r]) ++s;
        int run = s - r;
        ig = ig == 0 ? run : gcd_int(ig, run);
        r = s;
    }

    int jg = 0;
    for (int c = 0; c < W; ) {
        int s = c + 1;
        while (s < W) {
            bool same = true;
            for (int r = 0; r < H; ++r) {
                if (G[r][s] != G[r][c]) { same = false; break; }
            }
            if (!same) break;
            ++s;
        }
        int run = s - c;
        jg = jg == 0 ? run : gcd_int(jg, run);
        c = s;
    }

    int n = H / ig, m = W / jg;
    cout << n << ' ' << m << '\n';
    for (int r = 0; r < H; r += ig) {
        for (int c = 0; c < W; c += jg) cout << G[r][c];
        cout << '\n';
    }
    return 0;
}