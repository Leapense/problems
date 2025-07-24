#include "testlib.h"
#include <bits/stdc++.h>

using ull = unsigned long long;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ull MAX_AB = (argc > 1) ? strtoull(argv[1], nullptr, 10) : (ull)1'000'000'000'000'000'000ULL;
    ull MAX_K = (argc > 2) ? strtoull(argv[2], nullptr, 10) : MAX_AB;

    if (argc > 3) rnd.setSeed(strtoull(argv[3], nullptr, 10));

    ull a = rnd.next(1ULL, MAX_AB);
    ull b = rnd.next(a, MAX_AB);
    ull k = rnd.next(0ULL, MAX_K);

    println(a);
    println(b);
    println(k);

    return 0;
}