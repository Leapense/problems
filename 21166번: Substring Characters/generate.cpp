#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc != 4) {
        quitf(_fail, "Usage: %s T minLen maxLen", argv[0]);
    }

    int T = atoi(argv[1]);
    int minLen = atoi(argv[2]);
    int maxLen = atoi(argv[3]);

    ensure(minLen >= 1 && maxLen >= minLen && T >= 1);

    const string ALPH = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    for (int tc = 0; tc < T; ++tc) {
        int n = rnd.next(minLen, maxLen);
        string s;
        s.reserve(n);

        if (tc == 0) {
            s += ALPH[rnd.next(0, 61)];
        } else if (tc == 1) {
            char c = ALPH[rnd.next(0, 61)];
            s.assign(n, c);
        } else if (tc == 2) {
            s = ALPH;
            while ((int)s.size() < n) {
                s += ALPH[rnd.next(0, 61)];
            }

            shuffle(s.begin(), s.end());
            s.resize(n);
        } else {
            for (int i = 0; i < n; ++i) {
                s += ALPH[rnd.next(0, 61)];
            }
        }

        println(s);
    }

    return 0;
}