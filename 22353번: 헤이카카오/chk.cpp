// chk.cpp (fixed)
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static long double computeFromParams(int a, int d, int k) {
    long double p = (long double)d / 100.0L;
    long double g = 1.0L + (long double)k / 100.0L;
    long double survival = 1.0L;
    long double expected_games = 0.0L;
    const long double TH = 1.0L - 1e-18L;

    while (true) {
        expected_games += survival;
        if (p >= TH) break;
        survival *= (1.0L - p);
        p *= g;
        if (p > 1.0L) p = 1.0L;
    }
    return (long double)a * expected_games;
}

int main(int argc, char* argv[]) {
    // checker <input> <output> <answer>
    registerTestlibCmd(argc, argv);

    // 입력으로부터 직접 정답 계산 (seek 필요 X)
    int a = inf.readInt(1, 100, "a");
    int d = inf.readInt(1, 100, "d");
    int k = inf.readInt(1, 100, "k");
    // 필요하면 엄격히: inf.readEoln(); inf.readEof();

    long double corr = computeFromParams(a, d, k);

    // 참가자 출력: readDouble 시그니처 수정
    double got = ouf.readDouble(-1e300, 1e300, "answer");
    ouf.readEof();

    long double diff = fabsl((long double)got - corr);
    long double tol  = max(1e-6L, 1e-12L * fabsl(corr));

    if (diff > tol) {
        quitf(_wa, "Wrong answer: got=%.12Lf, expected=%.12Lf, diff=%.12Lf > tol=%.12Lf",
              (long double)got, corr, diff, tol);
    }
    quitf(_ok, "Accepted: got=%.12Lf within tol=%.12Lf", (long double)got, tol);
}
