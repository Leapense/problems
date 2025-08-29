#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        int d, x, s;
        cin >> d >> x >> s;
        long long min_pl = (1LL << 60);
        long long min_ps = (1LL << 60);
        long long lemon_inv = 0;
        long long sugar_inv = 0;
        long long total = 0;
        for (int i = 0; i < d; i++) {
            int c, pl, ps;
            cin >> c >> pl >> ps;
            if (pl < min_pl) min_pl = pl;
            if (ps < min_ps) min_ps = ps;
            long long need_lemons = 1LL * c * x;
            if (lemon_inv < need_lemons) {
                long long buy = need_lemons - lemon_inv;
                total += buy * min_pl;
                lemon_inv += buy;
            }

            lemon_inv -= need_lemons;
            long long need_sugar = 1LL * c * s;
            if (sugar_inv < need_sugar) {
                long long add = need_sugar - sugar_inv;
                long long bags = (add + 80 - 1) / 80;
                total += bags * min_ps;
                sugar_inv += bags * 80;
            }
            sugar_inv -= need_sugar;
        }

        cout << total << "\n";
    }

    return 0;
}