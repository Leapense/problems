#include <testlib.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    if (argc < 3) {
        quitf(_fail, "Usage: %s <T> <MAX_N> [mode]", argv[0]);
    }

    int T = atoi(argv[1]);
    long long M = atoll(argv[2]);
    string mode = (argc >= 4) ? string(argv[3]) : "mix";

    ensuref(T >= 1, "T must be >= 1");
    ensuref(M >= 1, "MAX_N must be >= 1");
    ensuref(M <= 1'000'000'000LL, "MAX_N too large (>= 1e9) - adjust if really needed)");

    vector<long long> ns;
    ns.reserve(T);

    for (int i = 0; i < T; ++i)
    {
        long long n = 1;
        if (mode == "small") {
            long long hi = min<long long>(M, 1000);
            n = rnd.next(1LL, hi);
        } else if (mode == "large") {
            long long lo = max<long long>(1, M - 999);
            n = rnd.next(lo, M);
        } else if (mode == "edge") {
            if (i == 0) n = 1;
            else if (i == 1) n = 2;
            else if (i == 2) n = 3;
            else if (i == 3) n = M;
            else n = rnd.next(1LL, M);
        } else {
            int type = rnd.next(0, 4);
            if (type == 0) n = 1;
            else if (type == 1) n = M;
            else if (type == 2) n = rnd.next(max<long long>(1, M - 999), M);
            else n = rnd.next(1LL, M);
        }
        ns.push_back(n);
    }

    println(T);
    for (long long v : ns) println(v);
    return 0;
}