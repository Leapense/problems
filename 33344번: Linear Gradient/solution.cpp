#include <bits/stdc++.h>
using namespace std;
using LD = long double;

struct Interval {
    LD L, R;
    bool empty;
};

void inter_all(Interval &I, LD a, LD d, bool ge, LD T) {
    if (I.empty) return;
    if (fabsl(d) == 0.0L) {
        bool ok = ge ? (a >= T) : (a <= T);
        if (!ok) I.empty = true;
        return;
    }
    LD s0 = (T - a) / d;
    if (ge) {
        if (d > 0) I.L = max(I.L, s0);
        else       I.R = min(I.R, s0);
    } else {
        if (d > 0) I.R = min(I.R, s0);
        else       I.L = max(I.L, s0);
    }
    if (I.L > I.R) I.empty = true;
}

LD area_of(LD dx, LD hL, LD hR, Interval I) {
    if (I.empty) return 0.0L;
    LD sL = max<LD>(0.0L, I.L);
    LD sR = min<LD>(1.0L, I.R);
    if (sL > sR) return 0.0L;
    LD ds = sR - sL;
    LD quad = (sR * sR - sL * sL);
    return fabsl(dx) * (hL * ds + 0.5L * (hR - hL) * quad);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x1, y1, y2, rl, gl, bl;
    long long x2, y3, y4, rr, gr, br;
    if (!(cin >> x1 >> y1 >> y2 >> rl >> gl >> bl)) return 0;
    if (!(cin >> x2 >> y3 >> y4 >> rr >> gr >> br)) return 0;

    LD dx = (LD)x2 - (LD)x1;
    LD hL = (LD)y2 - (LD)y1;
    LD hR = (LD)y4 - (LD)y3;

    if (hL < 0 && hR < 0){ hL = -hL; hR = -hR; }

    LD ar = (LD)rl, dr = (LD)rr - (LD)rl;
    LD ag = (LD)gl, dg = (LD)gr - (LD)gl;
    LD ab = (LD)bl, db = (LD)br - (LD)bl;

    Interval IR{-1e100L, 1e100L, false};
    inter_all(IR, ar, dr, true, 150.0L);
    inter_all(IR, ag, dg, false, 75.0L);
    inter_all(IR, ab, db, false, 75.0L);

    Interval IG{-1e100L, 1e100L, false};
    inter_all(IG, ag, dg, true, 150.0L);
    inter_all(IG, ar, dr, false, 75.0L);
    inter_all(IG, ab, db, false, 75.0L);

    Interval IB{-1e100L, 1e100L, false};
    inter_all(IB, ab, db, true, 150.0L);
    inter_all(IB, ar, dr, false, 75.0L);
    inter_all(IB, ag, dg, false, 75.0L);

    LD aR = area_of(dx, hL, hR, IR);
    LD aG = area_of(dx, hL, hR, IG);
    LD aB = area_of(dx, hL, hR, IB);

    cout.setf(std::ios::fixed);
    cout << setprecision(12);
    cout << aR << "\n" << aG << "\n" << aB << "\n";
    return 0;
}