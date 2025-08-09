#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static constexpr int MIN_N = 1;
static constexpr int MAX_N = 1500;
static constexpr int MIN_V = 1;
static constexpr int MAX_V = 1000;

struct SuiteCfg {
    int extraRandom = 6;
    int randNLo = 1, randNHi = 1500;
    int randMLo = 1, randMHi = 1000;
};

static vector<int> uniformVec(int n, int val) {
    return vector<int>(n, val);
}

static vector<int> randomVec(int n, int lo = MIN_V, int hi = MAX_V) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd.next(lo, hi);
    return a;
}

static vector<int> smallAlphabetVec(int n, int alphabet = 3) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd.next(1, max(1, alphabet));
    return a;
}

static vector<int> spikeVec(int n, int baseVal = 1, int spikeVal = 1000) {
    vector<int> a(n, baseVal);
    if (n >= 1) {
        int pos = rnd.next(0, n - 1);
        a[pos] = spikeVal;
    }

    return a;
}

static vector<int> risingCappedVec(int n) {
    vector<int> a(n);
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        a[i] = cur;
        ++cur;
        if (cur > MAX_V) cur = 1;
    }
    return a;
}

static vector<int> alternatingVec(int n, int a = 1, int b = 1000) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = (i & 1) ? b : a;
    return v;
}

static void printCase(const vector<int>& h, const vector<int>& w) {
    cout << h.size() << ' ' << w.size() << '\n';
    for (int x : h) cout << x << "\n";
    for (int x : w) cout << x << "\n";
}

static void genBoundarySuite(const SuiteCfg& cfg) {
    // 1) Minimal: N=1, M=1 (both = 1)
    printCase(uniformVec(1, 1), uniformVec(1, 1));

    // 2) N=1, M=max with all ones → lots of equal sums on the long side
    printCase(uniformVec(1, 1), uniformVec(MAX_N, 1));

    // 3) N=max, M=1 with all ones
    printCase(uniformVec(MAX_N, 1), uniformVec(1, 1));

    // 4) Max×Max, all ones → maximal collision counts
    printCase(uniformVec(MAX_N, 1), uniformVec(MAX_N, 1));

    // 5) Max×Max, all 1000s → large sums (stress potential overflow in other langs)
    printCase(uniformVec(MAX_N, 1000), uniformVec(MAX_N, 1000));

    {
        int n = MAX_N * 2 / 3;
        int m = MAX_N * 2 / 3;
        auto h = smallAlphabetVec(n, 3);
        auto w = h;
        printCase(h, w);
    }

    {
        int n = MAX_N;
        int m = MAX_N / 2;
        auto h = alternatingVec(n, 1, 1000);
        auto w = randomVec(m);
        printCase(h, w);
    }

    {
        int n = MAX_N / 2;
        int m = MAX_N;
        auto h = spikeVec(n, 1, 1000);
        auto w = spikeVec(m, 1, 1000);
        printCase(h, w);
    }

    {
        int n = 777;
        int m = 1234;
        auto h = risingCappedVec(n);
        auto w = randomVec(m);
        printCase(h, w);
    }

    {
        int n = 7, m = 9;
        auto h = smallAlphabetVec(n, 2);
        auto w = smallAlphabetVec(m, 3);
        printCase(h, w);
    }

    {
        int n = 1499, m = 1500;
        auto h = smallAlphabetVec(n, 2);
        auto w = smallAlphabetVec(m, 4);
        printCase(h, w);
    }

    for (int t = 0; t < cfg.extraRandom; ++t) {
        int n = rnd.next(cfg.randNLo, cfg.randNHi);
        int m = rnd.next(cfg.randMLo, cfg.randMHi);
        auto h = randomVec(n);
        auto w = randomVec(m);
        printCase(h, w);
    }
}

static void genRandomOnly(int T, int nLo, int nHi, int mLo, int mHi) {
    for (int t = 0; t < T; ++t) {
        int n = rnd.next(nLo, nHi);
        int m = rnd.next(mLo, mHi);
        auto h = randomVec(n);
        auto w = randomVec(m);
        printCase(h, w);
    }
}

static void genMaxOnes() {
    printCase(uniformVec(MAX_N, 1), uniformVec(MAX_N, 1));
}

static void genMaxRandom() {
    printCase(randomVec(MAX_N), randomVec(MAX_N));
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc < 3) {
        cerr << "Usage:\n"
             << "  " << argv[0] << " <seed> suite\n"
             << "  " << argv[0] << " <seed> rand <T> [nLo nHi mLo mHi]\n"
             << "  " << argv[0] << " <seed> max-ones\n"
             << "  " << argv[0] << " <seed> max-rand\n";
        // Fall back to a small suite if parameters are missing.
    }

    string mode = (argc >= 3 ? string(argv[2]) : string("suite"));

    if (mode == "suite") {
        SuiteCfg cfg;
        // You can tweak these if desired:
        cfg.extraRandom = 6;
        cfg.randNLo = 1; cfg.randNHi = 1500;
        cfg.randMLo = 1; cfg.randMHi = 1500;

        genBoundarySuite(cfg);
    } else if (mode == "rand") {
        int T = (argc >= 4 ? atoi(argv[3]) : 10);
        int nLo = (argc >= 5 ? atoi(argv[4]) : 1);
        int nHi = (argc >= 6 ? atoi(argv[5]) : 1500);
        int mLo = (argc >= 7 ? atoi(argv[6]) : 1);
        int mHi = (argc >= 8 ? atoi(argv[7]) : 1500);
        nLo = max(nLo, MIN_N); nHi = min(nHi, MAX_N);
        mLo = max(mLo, MIN_N); mHi = min(mHi, MAX_N);
        genRandomOnly(T, nLo, nHi, mLo, mHi);
    } else if (mode == "max-ones") {
        genMaxOnes();
    } else if (mode == "max-rand") {
        genMaxRandom();
    } else {
        // Unknown mode → default suite
        genBoundarySuite(SuiteCfg{});
    }

    // Terminator
    cout << "0 0\n";
    return 0;
}