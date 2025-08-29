#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        int d, x, s;
        scanf("%d %d %d", &d, &x, &s);
        long long min_pl = 1LL << 60;
        long long min_ps = 1LL << 60;
        long long lemon_inv = 0;
        long long sugar_inv = 0;
        long long total = 0;
        for (int i = 0; i < d; i++) {
            int c;
            int pl, ps;
            scanf("%d %d %d", &c, &pl, &ps);
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

        printf("%lld\n", total);
    }

    return 0;
}