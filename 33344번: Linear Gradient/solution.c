#include <stdio.h>
#include <math.h>

typedef long double LD;

typedef struct {
    LD L, R;
    int empty;
} Interval;

static void inter_all(Interval *I, LD a, LD d, int ge, LD T) {
    if (I->empty) return;
    if (fabsl(d) == 0.0L) {
        int ok = ge ? (a >= T) : (a <= T);
        if (!ok) {
            I->empty = 1;
        }
        return;
    }
    LD s0 = (T - a) / d;
    if (ge) {
        if (d > 0) { if (s0 > I->L) I->L = s0; }
        else       { if (s0 < I->R) I->R = s0; }
    } else {
        if (d > 0) { if (s0 < I->R) I->R = s0; }
        else       { if (s0 > I->L) I->L = s0; }
    }
    if (I->L > I->R) I->empty = 1;
}

static LD area_of(LD dx, LD hL, LD hR, Interval I) {
    if (I.empty) return 0.0L;
    LD sL = I.L < 0.0L ? 0.0L : I.L;
    LD sR = I.R > 1.0L ? 1.0L : I.R;
    if (sL > sR) return 0.0L;
    LD ds = sR - sL;
    LD quad = (sR * sR - sL * sL);
    return fabsl(dx) * (hL * ds + 0.5L * (hR - hL) * quad);
}

int main(void) {
    long long x1, y1, y2, rl, gl, bl;
    long long x2, y3, y4, rr, gr, br;
    if (scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &y2, &rl, &gl, &bl) != 6) return 0;
    if (scanf("%lld %lld %lld %lld %lld %lld", &x2, &y3, &y4, &rr, &gr, &br) != 6) return 0;

    LD dx = (LD)x2 - (LD)x1;
    LD hL = (LD)y2 - (LD)y1;
    LD hR = (LD)y4 - (LD)y3;

    if (hL < 0 && hR < 0) { hL = -hL; hR = -hR; }

    LD ar = (LD)rl, dr = (LD)rr - (LD)rl;
    LD ag = (LD)gl, dg = (LD)gr - (LD)gl;
    LD ab = (LD)bl, db = (LD)br - (LD)bl;

    Interval IR = (Interval){-1e100L, 1e100L, 0};
    inter_all(&IR, ar, dr, 1, 150.0L);
    inter_all(&IR, ag, dg, 0, 75.0L);
    inter_all(&IR, ab, db, 0, 75.0L);

    Interval IG = (Interval){-1e100L, 1e100L, 0};
    inter_all(&IG, ag, dg, 1, 150.0L);
    inter_all(&IG, ar, dr, 0, 75.0L);
    inter_all(&IG, ab, db, 0, 75.0L);

    Interval IB = (Interval){-1e100L, 1e100L, 0};
    inter_all(&IB, ab, db, 1, 150.0L);
    inter_all(&IB, ar, dr, 0, 75.0L);
    inter_all(&IB, ag, dg, 0, 75.0L);

    LD aR = area_of(dx, hL, hR, IR);
    LD aG = area_of(dx, hL, hR, IG);
    LD aB = area_of(dx, hL, hR, IB);

    printf("%.12Lf\n%.12Lf\n%.12Lf\n", aR, aG, aB);
    return 0;
}