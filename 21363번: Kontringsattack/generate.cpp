#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc < 2) {
        quitf(_fail, "Usage: N [scenario] [seed]");
    }

    const int N = atoi(argv[1]);
    string mode = (argc >= 3) ? argv[2] : "random";
    if (argc >= 4) rnd.setSeed(atoi(argv[3]));

    auto randScore = []() { return rnd.next(0, 1'000'000); };

    cout << N << "\n";

    for (int i = 0; i < N; ++i) {
        int F, S;

        if (mode == "all_f_high") {
            F = rnd.next(1, 1'000'000);
            S = rnd.next(0, F - 1);
        } else if (mode == "all_s_high") {
            S = rnd.next(1, 1'000'000);
            F = rnd.next(0, S - 1);
        } else if (mode == "small_diff") {
            F = randScore();
            int delta = rnd.next(1, 5) * (rnd.next(0, 1) ? 1 : -1);
            S = clamp(F + delta, 0, 1'000'000);
            if (F == S) S = (S + 1) % 1'000'001;
        } else if (mode == "big_diff") {
            F = randScore();
            int delta = rnd.next(900'000, 1'000'000) * (rnd.next(0, 1) ? 1 : -1);
            S = clamp(F + delta, 0, 1'000'000);
            if (F == S) S = (S + 123456) % 1'000'001;
        } else if (mode == "clustered") {
            static int commonD = rnd.next(1, 1'000'000);
            if (rnd.next(0, 1)) {
                int base = randScore();
                if (rnd.next(0, 1)) {
                    F = base;
                    S = clamp(base + commonD, 0, 1'000'000);
                } else {
                    S = base;
                    F = clamp(base + commonD, 0, 1'000'000);
                }
                if (F == S) S = (S + 1) % 1'000'001;
            } else {
                F = randScore();
                S = randScore();
            }
        } else if (mode == "alternating") {
            if (i % 2 == 0) {
                F = rnd.next(1, 1'000'000);
                S = rnd.next(0, F - 1);
            } else {
                S = rnd.next(1, 1'000'000);
                F = rnd.next(0, S - 1);
            }
        } else {
            F = randScore();
            S = randScore();
        }

        cout << F << ' ' << S << "\n";
    }

    return 0;
}