#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

struct Args {
    string mode = "mixed";
    int tests = 1;
} args;

int64 gcdll(int64 a, int64 b) {
    return b ? gcdll(b, a % b) : llabs(a);
}

struct Quad {
    int64 p, q;
    int N, M;
};

Quad makeSolvable() {
    int S = rnd.next(2, 1000);
    int r = rnd.next(1, S / 2);
    int g = S - r;

    int64 p0 = 2LL * r * g;
    int64 q0 = 1LL * S * (S - 1);
    int64 g_ = gcdll(p0, q0);
    int64 p = p0 / g_;
    int64 q = q0 / g_;

    int N = rnd.next(2, S);
    int M = rnd.next(S, 1000);

    return {p, q, N, M};
}

Quad makeUnsolvable() {
    int S = rnd.next(2, 1000);
    int N = S, M = S;

    int64 p, q;
    do {
        p = rnd.next(1, 2'000'000);
        q = rnd.next(1, 2'000'000);
    } while (gcdll(p, q) != 1);

    if ((p * 1LL * S * (S - 1)) % (2LL * q) == 0) {
        ++p;
        if (gcdll(p, q) != 1) ++p;
    }

    return {p, q, N, M};
}

void parseCmd(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string k = argv[i];
        if (k == "--mode" && i + 1 < argc) args.mode = argv[++i];
        else if (k == "--tests" && i + 1 < argc) args.tests = atoi(argv[++i]);
        else if (k == "--seed" && i + 1 < argc) {
            long long seed = atoll(argv[++i]);
            rnd.setSeed(seed);
        }
    }

    ensuref(args.mode == "solvable" || args.mode == "unsolvable" || args.mode == "mixed", "mode must be solvable|unsolvable|mixed");
    ensuref(args.tests > 0, "tests must be positive");
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    parseCmd(argc, argv);

    for (int t = 0; t < args.tests; ++t) {
        Quad q;
        if (args.mode == "solvable") q = makeSolvable();
        else if (args.mode == "unsolvable") q = makeUnsolvable();
        else q = (rnd.next(0, 1) ? makeSolvable() : makeUnsolvable());

        printf("%lld %lld %d %d", q.p, q.q, q.N, q.M);
    }

    return 0;
}